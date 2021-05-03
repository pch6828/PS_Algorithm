class DiningPhilosophers {
public:
    bool forks[5];
    condition_variable cv;
    mutex mtx;
    DiningPhilosophers() {
        for(int i = 0; i < 5; i++){
            forks[i] = false;
        }
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		unique_lock<mutex>lock(mtx);
        cv.wait(lock, [this, philosopher]{return !forks[(philosopher+1)%5]&&!forks[philosopher];});
        forks[(philosopher+1)%5] = true;
        forks[philosopher] = true;
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
        forks[(philosopher+1)%5] = false;
        forks[philosopher] = false;
        lock.unlock();
        cv.notify_all();
    }
};