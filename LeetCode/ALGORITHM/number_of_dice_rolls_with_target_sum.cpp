class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int dp[1001][31] = {0,};
        dp[0][0] = 1;
        
        for(int i = 1; i <= target; i++){
            for(int j = 1; j <= n; j++){
                for(int l = 1; l <= min(k, i); l++){
                    dp[i][j] += dp[i-l][j-1];
                    dp[i][j] %= 1000000007;
                }
            }
        }
        
        return dp[target][n];
    }
};