#include <mutex>
#include <condition_variable>
#include <functional>

using namespace std;

class Foo {
    private:
    mutex m;
    condition_variable cv;
    int step = 0;
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        printFirst();
        {
            lock_guard<mutex> lock(m);
            step = 1;
        }
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        {
            unique_lock<mutex> lock(m);
            cv.wait(lock,[&]{return step>=1;});
        }
        printSecond();
        {
            lock_guard<mutex> lock(m);
            step = 2;
        }
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        {
            unique_lock<mutex> lock(m);
            cv.wait(lock,[&]{return step>=2;});
        }
        printThird();
    }
};