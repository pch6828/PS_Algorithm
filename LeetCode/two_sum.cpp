class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>answer;
        bool flag = true;
        for(int i = 0; i < nums.size() && flag; i++){
            for(int j = i+1; j < nums.size() && flag; j++){
                if(nums[i]+nums[j]==target){
                    answer.push_back(i);
                    answer.push_back(j);
                    flag = false;
                }
            }
        }
        return answer;
    }
};