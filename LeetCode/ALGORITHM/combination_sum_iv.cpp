class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unsigned int dp[1001] = {0,};
        dp[0] = 1;
        for(int i = 1; i <= target; i++){
            dp[i] = 0;
            for(int num : nums){
                if(num <= i){
                    dp[i]+=dp[i-num];
                }
            }
        }
        return dp[target];
    }
};