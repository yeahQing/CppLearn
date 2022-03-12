#pragma once
#ifndef _THREAD_POOL_HPP
#define _THREAD_POOL_HPP

#include <iostream>
#include <functional>
#include <thread>  /* 线程 */
#include <condition_variable> /* 条件变量 */
#include <future> /* 异步函数 */
#include <atomic> /* 原子操作 */
#include <vector> /* 线程池向量 */
#include <queue> /* 任务队列 */

// 命名空间
namespace mypool {
    class TaskExecutor;
}

class mypool::TaskExecutor {
    // 任务是一个函数
    using Task = std::function<void()>;
private:
    // 线程池
    std::vector<std::thread> pool; // 向量里都是线程对象
    // 任务队列
    std::queue<Task> tasks;
    // 同步
    std::mutex m_task; // 互斥锁
    std::condition_variable cv_task; // 条件变量

    // 是否关闭提交
    std::atomic<bool> stop;

public:
    TaskExecutor(size_t size = 4): stop{false} {
        size = size < 1 ? 1 : size;
        for (size_t i = 0; i < size; ++i)
        {
            pool.emplace_back(&TaskExecutor::schedual, this); // push_back(std::thread{...})
        }
    }

    // 析构
    ~TaskExecutor() {
        // 遍历向量
        for (std::thread& thread : pool)
        {
            // thread.detach(); // 让线程自生自灭
            thread.join(); // 等待任务结束，前提是线程一定会执行完
        }
    }

    // 停止任务提交
    void shutdown() {
        // atomic
        this->stop.store(true);
    }

    // 重启任务提交
    void restart() {
        this->stop.store(false);
    }

    // 提交一个任务
    template<class F, class... Args>
    auto commit(F&& f, Args&&... args) -> std::future<decltype(f(args...))> {
        if (stop.load()) { // stop == true?
            throw std::runtime_error("task executor have closed commit. ");
        } 

        using RetType = decltype(f(args...)); // typename std::result_of<F(Args...)>::type 函数f的返回值类型
        auto task = std::make_shared<std::packaged_task<RetType()>>(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...)
        ); // 将函数和参数绑定到一起，并交给智能指针所有

        {
            std::lock_guard<std::mutex> lock {m_task}; // 互斥锁
            tasks.emplace([task]() { // push(Task{...})
                (*task)();
            });
        }

        cv_task.notify_all(); // 唤醒线程执行

        std::future<RetType> future = task->get_future();
        
        return future;
    }

private:
    // 获取一个待执行的task
    Task get_one_task() {
        std::unique_lock<std::mutex> lock {m_task}; // 互斥锁
        cv_task.wait(lock, [this]() {return !tasks.empty();}); // wait直到有task

        Task task {std::move(tasks.front())}; // 取一个task
        tasks.pop();
        return task;
    }

    // 任务调度
    void schedual() {
        while (true)
        {
            if (Task task = get_one_task())
            {
                task();
            }
            else
            {
                return; // done
            }
        }
        
    }

};

#endif
