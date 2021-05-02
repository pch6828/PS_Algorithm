class Foo {
private:
    mutex mtx;
    condition_variable cv;
    int flag;
public:
    Foo() {
        flag = 1;
    }
    
    void first(function<void()> printFirst) {
        unique_lock<mutex>lock(mtx);
        cv.wait(lock, [this]{return flag==1;});
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        flag++;
        lock.unlock();
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex>lock(mtx);
        cv.wait(lock, [this]{return flag==2;});
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        flag++;
        lock.unlock();
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex>lock(mtx);
        cv.wait(lock, [this]{return flag==3;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        flag++;
        lock.unlock();
        cv.notify_all();
    }
};