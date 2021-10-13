class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>answer(2, -1);
        
        vector<int>::iterator l, u;
        
        if(nums.empty()||
           nums.back() < target||
           *(l = lower_bound(nums.begin(), nums.end(), target)) != target){
            return answer;
        }
        
        u = upper_bound(nums.begin(), nums.end(), target);
        
        answer[0] = l - nums.begin();
        answer[1] = u - nums.begin() - 1;
        
        return answer;
    }
};