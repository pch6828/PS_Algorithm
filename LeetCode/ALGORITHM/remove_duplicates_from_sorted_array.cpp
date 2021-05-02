class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>result;
        for(int i : nums){
            if(result.empty()||result.back()!=i){
                result.push_back(i);
            }
        }
        nums = result;
        return nums.size();
    }
};