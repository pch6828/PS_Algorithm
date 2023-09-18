class FreqStack {
    map<int, int>freq;
    vector<vector<int>>s;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;

        if(s.size()<freq[val]){
            s.emplace_back();
            s.back().push_back(val);
        }else{
            s[freq[val]-1].push_back(val);
        }
    }
    
    int pop() {
        int res = s.back().back();
        s.back().pop_back();
        if(s.back().size()==0)
            s.pop_back();
        freq[res]--;
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */