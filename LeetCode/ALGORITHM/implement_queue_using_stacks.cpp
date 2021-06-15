class MyQueue {
private:
    stack<int>a, b;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        //Do Nothing
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!a.empty()){
            b.push(a.top());
            a.pop();
        }
        a.push(x);
        while(!b.empty()){
            a.push(b.top());
            b.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int answer = a.top();
        a.pop();
        return answer;
    }
    
    /** Get the front element. */
    int peek() {
        return a.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return a.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */