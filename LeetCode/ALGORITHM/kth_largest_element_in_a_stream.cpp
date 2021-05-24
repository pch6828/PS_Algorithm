class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>>pq;
    int target;
public:
    KthLargest(int k, vector<int>& nums) {
        this->target = k;
        for(auto i : nums){
            this->pq.push(i);
        }
        while(this->target < pq.size()){
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(this->target < pq.size()){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */