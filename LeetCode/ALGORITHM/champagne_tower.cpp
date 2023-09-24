class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[100][100] = {0,};

        dp[0][0] = poured;

        for(int i = 0; i < query_row; i++){
            for(int j = 0; j <= i; j++){
                dp[i+1][j] += max(dp[i][j]-1, 0.0) / 2;
                dp[i+1][j+1] += max(dp[i][j]-1, 0.0) / 2;
            }
        }

        return min(dp[query_row][query_glass], 1.0);
    }
};