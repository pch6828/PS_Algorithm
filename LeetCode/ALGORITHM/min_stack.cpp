class MinStack {
private:
    vector<pair<int, int>>store;    
public:
    /** initialize your data structure here. */
    MinStack() {
        //Do Nothing
    }
    
    void push(int val) {
        if(store.empty()){
            store.push_back({val, val});
        }else{
            store.push_back({val, min(val, store.back().second)});
        }
    }
    
    void pop() {
        store.pop_back();
    }
    
    int top() {
        return store.back().first;
    }
    
    int getMin() {
        return store.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */