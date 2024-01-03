class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>dp;
        dp.push_back(0);

        for(int i = 0; i < nums.size(); i++){
            for(int j = 1; j <= nums[i]; j++){
                int dst = i+j;
                if(dst >= nums.size())
                    break;
                if(dp.size() == dst){
                    dp.push_back(dp[i]+1);
                }else{
                    dp[dst] = min(dp[dst], dp[i]+1);
                }
            }
        }

        return dp.back();
    }
};