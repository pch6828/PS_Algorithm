class MyStack {
private:
    queue<int>q[2];
    int idx = 0;
public:
    /** Initialize your data structure here. */
    MyStack() {
        //Do Nothing
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q[idx].push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while(q[idx].size()!=1){
            q[(idx+1)%2].push(q[idx].front());
            q[idx].pop();
        }
        int answer = q[idx].front();
        q[idx].pop();
        idx = (idx+1)%2;
        
        return answer;
    }
    
    /** Get the top element. */
    int top() {
        int answer;
        while(!q[idx].empty()){
            answer = q[idx].front();
            q[(idx+1)%2].push(q[idx].front());
            q[idx].pop();
        }
        idx = (idx+1)%2;
        
        return answer;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q[idx].empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */