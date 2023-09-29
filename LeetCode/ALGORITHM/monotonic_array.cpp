class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int cmp = 0;

        for(int i = 1; i < nums.size(); i++){
            int tmp = (nums[i-1] == nums[i] ? 0 : (nums[i-1] < nums[i] ? -1 : 1));
            if(tmp && cmp && tmp != cmp)
                return false;
            if(tmp)
                cmp = tmp;
        }
        
        return true;
    }
};