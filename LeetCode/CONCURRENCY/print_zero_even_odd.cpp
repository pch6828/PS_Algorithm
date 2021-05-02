class ZeroEvenOdd {
private:
    int n;
    int target;
    mutex mtx;
    condition_variable cv;
    
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        target = 1;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(target<=2*n){
            unique_lock<mutex>lock(mtx);
            cv.wait(lock, [this]{return target%2==1;});           
            if(target<=2*n){
                printNumber(0);
            }
            target++;
            lock.unlock();
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while(target<=2*n){
            unique_lock<mutex>lock(mtx);
            cv.wait(lock, [this]{return target%4==0;});
            if(target<=2*n){
                printNumber(target/2);
            }
            target++;
            lock.unlock();
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while(target<=2*n){
            unique_lock<mutex>lock(mtx);
            cv.wait(lock, [this]{return target%4!=0&&target%2==0;}); 
            if(target<=2*n){
                printNumber(target/2);
            }
            target++;
            lock.unlock();
            cv.notify_all();
        }
    }
};