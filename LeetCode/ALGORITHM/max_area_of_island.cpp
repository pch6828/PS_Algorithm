class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    int getAreaOfIsland(vector<vector<int>>& grid, int x, int y){
        grid[x][y] = 0;
        int area = 1;
        for(int i = 0; i < 4; i++){
            int tx = dx[i]+x;
            int ty = dy[i]+y;
            if(tx<grid.size()&&tx>=0&&ty<grid[0].size()&&ty>=0&&grid[tx][ty]==1){
                area+=getAreaOfIsland(grid, tx, ty);
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j]){
                    ans = max(ans, getAreaOfIsland(grid, i, j));    
                }
            }
        }
        return ans;
    }
};