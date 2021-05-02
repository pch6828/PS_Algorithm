class FooBar {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    bool flag;
public:
    FooBar(int n) {
        this->n = n;
        flag = false;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex>lock(mtx);
            cv.wait(lock, [this]{return !flag;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            flag = !flag;
            lock.unlock();
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex>lock(mtx);
            cv.wait(lock, [this]{return flag;});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            flag = !flag;
            lock.unlock();
            cv.notify_all();
        }
    }
};