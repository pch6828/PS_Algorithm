class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if(maxMove==0){
            return 0;
        }
        int mod = 1000000007;
        
        int dp[50][50][50] = {{{0,},},};
        int dx[] = {0,0,-1,1};
        int dy[] = {1,-1,0,0};
        dp[0][startRow][startColumn] = 1;
        
        for(int step = 1; step < maxMove; step++){
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    for(int k = 0; k < 4; k++){
                        int tx = i+dx[k];
                        int ty = j+dy[k];
                        if(tx>=0&&tx<m&&ty>=0&&ty<n){
                            dp[step][i][j]+=dp[step-1][tx][ty];
                            dp[step][i][j] %= mod;
                        }
                    }
                }
            }
        }
        int ans = 0;
        
        for(int step = 0; step < maxMove; step++){
            for(int i = 0; i < n; i++){
                ans+=dp[step][0][i];
                ans %= mod;
            }
            for(int i = 0; i < n; i++){
                ans+=dp[step][m-1][i];
                ans %= mod;
            }
            for(int i = 0; i < m; i++){
                ans+=dp[step][i][0];
                ans %= mod;
            }
            for(int i = 0; i < m; i++){
                ans+=dp[step][i][n-1];
                ans %= mod;
            }
        }
        
        return ans;
    }
};