class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int grid[101][101];
        
        for(int i = 0; i <= max(obstacleGrid.size(), obstacleGrid[0].size()); i++){
            grid[i][0] = grid[0][i] = 0;
        }
        
        grid[0][1] = 1;
        for(int i = 1; i <= obstacleGrid.size(); i++){
            for(int j = 1; j <= obstacleGrid[i-1].size(); j++){
                grid[i][j] = grid[i-1][j]+grid[i][j-1];
                if(obstacleGrid[i-1][j-1]){
                    grid[i][j] = 0;
                }
            }
        }
        
        return grid[obstacleGrid.size()][obstacleGrid[0].size()];
    }
};