class NumArray {
private:
    vector<int>arr;
    vector<int>sum_per_300;
public:
    NumArray(vector<int>& nums) {
        arr = nums;
        for(int i = 0; i < nums.size(); i++){
            if(i%300){
                sum_per_300.back()+=nums[i];
            }else{
                sum_per_300.push_back(nums[i]);
            }
        }
    }
    
    void update(int index, int val) {
        sum_per_300[index/300] += val-arr[index];
        arr[index] = val;
    }
    
    int sumRange(int left, int right) {
        int ans = 0;
        int sum_left = left/300;
        int sum_right = right/300;
        
        if(sum_left==sum_right){
            for(int i = left; i <= right; i++){
                ans+=arr[i];
            }
        }else{
            for(int i = left; i < ((left+300)/300)*300;i++){
                ans+=arr[i];
            }
            for(int i = (right/300)*300; i <= right; i++){
                ans += arr[i];
            }
            for(int i = sum_left+1; i <= sum_right-1; i++){
                ans += sum_per_300[i];
            }
        }
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */