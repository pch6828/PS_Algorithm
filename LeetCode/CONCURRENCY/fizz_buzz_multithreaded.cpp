class FizzBuzz {
private:
    int n;
    int target;
    mutex mtx;
    condition_variable cv;
    bool done;
public:
    FizzBuzz(int n) {
        this->n = n;
        target = 1;
        done = false;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(target<=n){
            unique_lock<mutex>lock(mtx);
            cv.wait(lock, [this]{return (target%3==0&&target%5!=0)||done;});
            if(target<=n){
                printFizz();
            }
            target++;
            if(target>n){
                done = true;
            }
            lock.unlock();
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(target<=n){
            unique_lock<mutex>lock(mtx);
            cv.wait(lock, [this]{return (target%3!=0&&target%5==0)||done;});
            if(target<=n){
                printBuzz();
            }
            target++;
            if(target>n){
                done = true;
            }
            lock.unlock();
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(target<=n){
            unique_lock<mutex>lock(mtx);
            cv.wait(lock, [this]{return (target%3==0&&target%5==0)||done;});
            if(target<=n){
                printFizzBuzz();
            }
            target++; 
            if(target>n){
                done = true;
            }
            lock.unlock();
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(target<=n){
            unique_lock<mutex>lock(mtx);
            cv.wait(lock, [this]{return (target%3!=0&&target%5!=0)||done;});
            if(target<=n){
                printNumber(target);
            }
            target++;
            if(target>n){
                done = true;
            }
            lock.unlock();
            cv.notify_all();
        }
    }
};