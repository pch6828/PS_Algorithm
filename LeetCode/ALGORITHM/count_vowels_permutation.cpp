class Solution {
private:
    static const int MOD = 1000000007;
public:
    int countVowelPermutation(int n) {
        int dp[20001][5];
        dp[1][0] = dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = 1;
        
        for(int i = 2; i <= n; i++){
            dp[i][0] = ((dp[i-1][1]+dp[i-1][2])%MOD+dp[i-1][4])%MOD;
            dp[i][1] = (dp[i-1][0]+dp[i-1][2])%MOD;
            dp[i][2] = (dp[i-1][1]+dp[i-1][3])%MOD;
            dp[i][3] = dp[i-1][2];
            dp[i][4] = (dp[i-1][2]+dp[i-1][3])%MOD;
        }
        
        int ans = 0;
        for(int i = 0; i < 5; i++){
            ans = (ans+dp[n][i])%MOD;
        }
        return ans;
    }
};