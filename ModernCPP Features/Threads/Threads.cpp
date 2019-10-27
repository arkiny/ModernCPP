#include <thread>
#include <future>
#include <iostream>
#include <vector>

auto Printsome()
{
    for (int i = 0; i < 1000000; ++i)
    {
        std::cout << "Thread Working: " << i << std::endl;
    }
    return 100;
}

std::mutex mtx;

auto main() -> int
{
    std::unique_lock<std::mutex> lock{mtx};
    //std::vector<std::thread> threads;

    //for (int num = 0; num < 3; ++num) {
    //    threads.emplace_back(std::thread([]() {
    //        for (int i = 0; i < 1000000; ++i)
    //        {
    //            std::cout << "Thread Working: " << i << std::endl;
    //        }
    //        }));
    //}

    //for (auto& thrd : threads)
    //{
    //    thrd.join();
    //}

    auto asynchandle = std::async(std::launch::async, &Printsome);
    /*
    for (int i = 0; i < 1000000; ++i)
    {
        std::cout << "Async Working" << std::endl;
    }*/
    
   // asynchandle.wait();
    auto result = asynchandle.get();

    return 0;
}