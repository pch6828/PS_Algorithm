class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        queue<pair<int, int>>bfs;
        int ans = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j]=='1'){
                    ans++;
                    bfs.push({i,j});
                    
                    grid[i][j] = '0';
                    
                    while(!bfs.empty()){
                        auto p = bfs.front();
                        bfs.pop();
                        
                        
                        for(int k = 0; k < 4; k++){
                            int tx = p.first + dx[k];
                            int ty = p.second + dy[k];
                            
                            if(tx>=0&&tx<grid.size()&&ty>=0&&ty<grid[i].size()&&grid[tx][ty]=='1'){
                                bfs.push({tx, ty});
                                grid[tx][ty] = '0';
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};