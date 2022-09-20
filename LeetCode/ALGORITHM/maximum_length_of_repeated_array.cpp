class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int dp[1001][1001] = {0};
        int ans = 0;
        
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                if(nums1[i]==nums2[j]){
                    dp[i+1][j+1] = 1+dp[i][j];
                    ans = max(ans, dp[i+1][j+1]);
                }
            }    
        }
        
        return ans;
    }
};