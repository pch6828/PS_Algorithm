class MedianFinder {
private:
    priority_queue<double, vector<double>, less<double>>a;
    priority_queue<double, vector<double>, greater<double>>b;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        //Do Nothing
    }
    
    void addNum(int num) {
        b.push(num);
        if(b.size()-a.size()==2){
            a.push(b.top());
            b.pop();
        }else if(!a.empty() && a.top()>b.top()){
            a.push(b.top());
            b.pop();
            b.push(a.top());
            a.pop();
        }
    }
    
    double findMedian() {
        if(a.size()==b.size()){
            return (a.top()+b.top())/2;
        }else{
            return b.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */