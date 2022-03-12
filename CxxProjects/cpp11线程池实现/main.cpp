#include "my_thread_pool.hpp"

void f()
{
    std::cout << "hello, f !" << std::endl;
}

struct G
{
    // 仿函数
    int operator() ()
    {
        std::cout << "hello, g!" << std::endl;
        return 42;
    }
};

int main()
{
    try {
        mypool::TaskExecutor executor {10};
        
        std::future<void> ff = executor.commit(f);
        std::future<int> fg = executor.commit(G{});

        std::future<std::string> fh = executor.commit([]() -> std::string {
            std::cout << "hello, h!" << std::endl;
            return "hello, fh!";
        });

        executor.shutdown();

        ff.get();
        std::cout << fg.get() << " " << fh.get() << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));

        executor.restart();
        executor.commit(f).get();

        std::cout << "end..." << std::endl;

        return 0;
    }
    catch (std::exception& e)
    {
        std::cout << "some unhappy happened... " << e.what() << std::endl;
    }
    
}