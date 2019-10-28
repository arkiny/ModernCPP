#include <thread>
#include <iostream>

auto DoSomeWorks()
{
    for (int i = 0; i < 100000 ; ++i)
    {
        std::cout << "Printing : " << i << std::endl;
    }
}

class BackGround_task
{
public:
    auto operator()() const
    {
        DoSomeWorks();
    }
};

struct BadFunc
{
    int& i;
    BadFunc(int& i_) : i(i_) {}
    auto operator() ()
    {
        for (std::size_t j = 0; j < 100000; ++j)
        {
            std::cout << i << std::endl;
        }
    }
};

// this one is a bad idea because it has dangling reference harzardness.
auto Oops()
{
    int some_local_var = 10;
    BadFunc badone(some_local_var);
    std::thread bad_thread(badone);
    //bad_thread.detach();
    bad_thread.join(); // <-- wait for finish, brute-force answer
}

// if one wants handling exception
auto TryCatchThread()
{
    int some_local_var = 10;
    BadFunc badone(some_local_var);
    std::thread thrd(badone);
    try
    {
        // do something main thread stuff
    }
    catch(std::exception e)
    {
        thrd.join(); // wait until thread done 
        throw e;
    }

    thrd.join();
}

class Thread_Guard
{
    std::thread& t;
public:
    explicit Thread_Guard(std::thread& t_) : t(t_) {};
    ~Thread_Guard()
    {
        if (t.joinable())
        {
            t.join();
        }
    }

    Thread_Guard(Thread_Guard&) = delete;
    Thread_Guard& operator=(const Thread_Guard&) = delete;
};

auto Using_RAII_ThreadGuard()
{
    int some_local_var = 10;
    BadFunc badone(some_local_var);
    std::thread thrd(badone);
    Thread_Guard guard(thrd);

    // do some main stuff
}


auto main() -> int
{
    // as callable function
    //std::thread my_thread(&DoSomeWorks);

    // as callable class
    //BackGround_task task;
    //std::thread my_callable_class_thread(task);

    // doesn't work
    //std::thread my_callable_class_thread2(BackGround_task());

    // works
    //std::thread my_callable_class_thread3(BackGround_task{});
    
    // parnethesis prevent intepretation as a function declaration
    // std::thread my_callable_class_thread3( (BackGround_task()) );

    // declare as variable also
    //std::thread my_callable_class_thread3{ BackGround_task() };

    // as a callable lambda
    //std::thread my_lambda_thread([]() {DoSomeWorks(); });

    Oops();

    return 0;
}