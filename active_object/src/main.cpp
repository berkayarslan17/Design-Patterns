#include <thread>
#include <queue>
#include <mutex>
#include <future>
#include <iostream>

typedef std::function<void()> operation;

class dispatch_q
{
    std::mutex qlock;
    std::queue<operation> ops_queue;
    std::condition_variable empty;

public:
    void put(operation op)
    {
        std::lock_guard<std::mutex> guard(qlock);
        ops_queue.push(op);
        empty.notify_one();
    }

    operation take()
    {
        std::unique_lock<std::mutex> lock(qlock);
        empty.wait(lock, [&]
                   { return !ops_queue.empty(); });

        operation op = ops_queue.front();
        ops_queue.pop();
        return op;
    }
};

class active_object
{
private:
    double val;
    dispatch_q dispatch_queue;
    std::atomic<bool> done;
    std::thread *runnable;

public:
    active_object() : val(0), done(false)
    {
        runnable = new std::thread(&active_object::run, this);
        // runnable = std::thread([=]{ run(); });
    }
    ~active_object() { runnable->join(); }

    double get_val() { return val; }

    void run()
    {
        while (!done)
        {
            dispatch_queue.take()();
        }
    }

    // This method returns a value, so it is blocking on the future result
    int do_something()
    {
        std::promise<int> return_val;
        auto runnable = [&]()
        {
            int ret = 999;
            return_val.set_value(ret);
        };

        dispatch_queue.put(runnable);
        return return_val.get_future().get();
    }

    // This method accesses the object's internal state from within the closure
    // Because the access to the ActiveObject is serialized, we can safely access
    // the object's internal state.
    void do_something_else()
    {
        dispatch_queue.put(([this]()
                            { this->val = 2.0; }));
    }

    // This method takes two params which we want to reference in the closure
    void do_something_with_params(int a, int b)
    {
        // This lambda function code will execute later from the context of a different thread,
        // but the integers {a, b} are bound now.
        // This is a beautiful way to write clear code
        dispatch_queue.put(([a, b]()
                            {
            std::cout << "this is the internal implementation of doSomethingWithParams(";
            std::cout << a << "," << b << ")\n"; }));
    }

    // This method takes two reference parameters so it must execute blocking
    void do_something_with_ref_params(int &a, int &b)
    {
        std::promise<void> return_val;
        // This lambda function code will execute later from the context of a different thread,
        // but the integers {a, b} are bound now.
        // This is a beautiful way to write clear code
        dispatch_queue.put(([&a, &b, &return_val]()
                            {
            std::cout << "this is the internal implementation of doSomethingWithReferenceParams(";
            std::cout << a << "," << b << ")\n";
            a = 1234;
            b = 5678;
            return_val.set_value(); }));

        return_val.get_future().get();
    }
};

int main(int argc, char **argv)
{
    active_object active;
    int i = active.do_something();
    // mix things up by starting another thread
    std::thread t1(&active_object::do_something_else, &active);
    active.do_something_with_params(5, 7);
    int a = 1, b = 2;
    active.do_something_with_ref_params(a, b);
    t1.join();
    return 0;
}