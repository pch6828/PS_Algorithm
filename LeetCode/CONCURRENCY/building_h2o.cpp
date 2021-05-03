class H2O {
private:
    int cnt;
    mutex mtx;
    condition_variable cv;
public:
    H2O() {
        cnt = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex>lock(mtx);
        cv.wait(lock, [this]{return cnt < 2;});
        cnt++;
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        lock.unlock();
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex>lock(mtx);
        cv.wait(lock, [this]{return cnt == 2;});
        cnt = 0;
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        lock.unlock();
        cv.notify_all();
    }
};