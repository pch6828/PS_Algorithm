#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>>dp(n+1, vector<bool>(n+1, false));
    for(auto e : results){
        dp[e[0]][e[1]] = true;
    }
    for(int k = 1; k <=n; k++){
        dp[k][k] = true;
        for(int i = 1; i <=n; i++){
            for(int j = 1; j <=n; j++){
                dp[i][j] = dp[i][j] | (dp[i][k]&dp[k][j]);
            }
        }
    }
    for(int i = 1; i <=n; i++){
        int chk = 0;
        for(int j = 1; j <=n; j++){
            chk+=dp[i][j]+dp[j][i];
        }
        if(chk==n+1){
            answer++;
        }
    }
    return answer;
}