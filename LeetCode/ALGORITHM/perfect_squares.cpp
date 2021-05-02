class Solution {
public:
    int numSquares(int n) {
        int dp[10001] = {0,};
        
        for(int i = 1; i <= n; i++){
            if(!dp[i]){
                dp[i] = INT_MAX;
            }
            for(int j = 1; j <= sqrt(i); j++){
                dp[i] = min(dp[i], dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};