class Solution {
public:
    int uniquePaths(int m, int n) {
        int grid[101][101];
        
        for(int i = 0; i <= max(m, n); i++){
            grid[i][0] = grid[0][i] = 0;
        }
        
        grid[0][1] = 1;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                grid[i][j] = grid[i-1][j]+grid[i][j-1];
            }
        }
        
        return grid[m][n];
    }
};