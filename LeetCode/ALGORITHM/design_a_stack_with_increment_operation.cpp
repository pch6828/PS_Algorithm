class CustomStack {
private:
    vector<int>arr;
    int top;
public:
    CustomStack(int maxSize) {
        arr = vector<int>(maxSize);
        top = -1;
    }
    
    void push(int x) {
        if(arr.size()==top+1){
            return;
        }
        arr[++top] = x;
    }
    
    int pop() {
        if(top==-1){
            return top;
        }
        return arr[top--];
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < k && i < arr.size(); i++){
            arr[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */