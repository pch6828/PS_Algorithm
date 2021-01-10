#include <string>
#include <vector>

using namespace std;

#define MOD 1000000007
int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for(auto p:puddles){
        dp[p[0]][p[1]] = -1;
    }

    dp[1][1] = 1;
    
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(dp[i][j]==-1){
                dp[i][j] = 0;
                continue;
            }
            dp[i][j]+=dp[i-1][j];
            dp[i][j]+=dp[i][j-1];
            dp[i][j] %= MOD;
        }
    }
    return dp[m][n];
}