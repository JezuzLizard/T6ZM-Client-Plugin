#include <stdinc.hpp>
#include "loader/component_loader.hpp"

#include "game/game.hpp"
#include "scheduler.hpp"
#include "io.hpp"

#include <utils/concurrency.hpp>
#include <utils/hook.hpp>

namespace scheduler
{
	namespace
	{
		struct task
		{
			std::function<bool()> handler{};
			std::chrono::milliseconds interval{};
			std::chrono::high_resolution_clock::time_point last_call{};
		};

		using task_list = std::vector<task>;

		class task_pipeline
		{
		public:
			void add(task&& task)
			{
				new_callbacks_.access([&task](task_list& tasks)
				{
					tasks.emplace_back(std::move(task));
				});
			}

			void execute()
			{
				callbacks_.access([&](task_list& tasks)
				{
					this->merge_callbacks();

					for (auto i = tasks.begin(); i != tasks.end();)
					{
						const auto now = std::chrono::high_resolution_clock::now();
						const auto diff = now - i->last_call;

						if (diff < i->interval)
						{
							++i;
							continue;
						}

						i->last_call = now;

						const auto res = i->handler();
						if (res == cond_end)
						{
							i = tasks.erase(i);
						}
						else
						{
							++i;
						}
					}
				});
			}

		private:
			utils::concurrency::container<task_list> new_callbacks_;
			utils::concurrency::container<task_list, std::recursive_mutex> callbacks_;

			void merge_callbacks()
			{
				callbacks_.access([&](task_list& tasks)
				{
					new_callbacks_.access([&](task_list& new_tasks)
					{
						tasks.insert(tasks.end(), std::move_iterator<task_list::iterator>(new_tasks.begin()), std::move_iterator<task_list::iterator>(new_tasks.end()));
						new_tasks = {};
					});
				});
			}
		};

		std::thread thread;
		task_pipeline pipelines[pipeline::count];

		void execute(const pipeline type)
		{
			assert(type >= 0 && type < pipeline::count);
			pipelines[type].execute();
		}

		void execute_server()
		{
			execute(pipeline::server);
		}

		void execute_frame()
		{
			execute(pipeline::frame);
		}

		void server_frame_stub(utils::hook::assembler& a)
		{
			a.pushad();
			a.call(execute_server);
			a.popad();

			a.jmp(SELECT(0x49E910, 0x5001A0));
		}

		void com_frame_try_block_function_stub(utils::hook::assembler& a)
		{
			a.pushad();
			a.call(execute_frame);
			a.popad();

			a.jmp(SELECT(0x0, 0x88BC9D));
		}
	}

	void schedule(const std::function<bool()>& callback, const pipeline type,
		const std::chrono::milliseconds delay)
	{
		assert(type >= 0 && type < pipeline::count);

		task task;
		task.handler = callback;
		task.interval = delay;
		task.last_call = std::chrono::high_resolution_clock::now();

		pipelines[type].add(std::move(task));
	}

	void loop(const std::function<void()>& callback, const pipeline type,
		const std::chrono::milliseconds delay)
	{
		schedule([callback]()
		{
			callback();
			return cond_continue;
		}, type, delay);
	}

	void once(const std::function<void()>& callback, const pipeline type,
		const std::chrono::milliseconds delay)
	{
		schedule([callback]()
		{
			callback();
			return cond_end;
		}, type, delay);
	}

	class component final : public component_interface
	{
	public:
		void post_unpack() override
		{
			thread = std::thread([]()
			{
				while (true)
				{
					execute(pipeline::async);
					std::this_thread::sleep_for(10ms);
				}
			});

			/*
			loop([]()
			{
				io::print_to_log("Still alive\n");
			}, scheduler::pipeline::frame, std::chrono::milliseconds(1000));
			*/
			utils::hook::jump(SELECT(0x4A59F7, 0x6AA2F7), utils::hook::assemble(server_frame_stub));

			utils::hook::jump(SELECT(0x0, 0x88BC98), utils::hook::assemble(com_frame_try_block_function_stub));
		}
	};
}

REGISTER_COMPONENT(scheduler::component)