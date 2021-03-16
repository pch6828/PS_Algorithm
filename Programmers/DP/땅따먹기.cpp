#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int dp[100001][4] = {0,};
    
    for(int i = 0; i < land.size(); i++){
        for(int j = 0; j < 4; j++){
            dp[i+1][j] = 0;
            for(int k = 1; k <= 3; k++){
                dp[i+1][j] = max(dp[i+1][j], land[i][j]+dp[i][(j+k)%4]);
            }
        }
    }
    int answer = 0;
    for(int i = 0; i < 4; i++){
        answer = max(answer, dp[land.size()][i]);
    }
    return answer;
}