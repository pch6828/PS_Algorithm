class Solution {
private:
    void flowWater(vector<vector<int>>& heights, vector<vector<bool>>& flowable, int n, int m, int x, int y){
        queue<pair<int, int>>bfs;
        bfs.push({x,y});
        flowable[x][y] = true;
        
        while(!bfs.empty()){
            auto p = bfs.front();
            bfs.pop();
            
            for(int i = 0; i < 4; i++){
                int tx = p.first + dx[i];
                int ty = p.second + dy[i];
                
                if(tx>=0&tx<n&&ty>=0&&ty<m&&heights[p.first][p.second]<=heights[tx][ty]&&!flowable[tx][ty]){
                    flowable[tx][ty] = true;
                    bfs.push({tx, ty});
                }
            }
        }
    }
        
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
        
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>>flowable1(n, vector<bool>(m, false));
        vector<vector<bool>>flowable2(n, vector<bool>(m, false));
        vector<vector<int>>ans;
        
        for(int i = 0; i < n; i++){
            flowWater(heights, flowable1, n, m, i, 0);
            flowWater(heights, flowable2, n, m, i, m-1);
        }
        for(int i = 0; i < m; i++){
            flowWater(heights, flowable1, n, m, 0, i);
            flowWater(heights, flowable2, n, m, n-1, i);
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(flowable1[i][j]&&flowable2[i][j]){
                    ans.emplace_back();
                    ans.back().push_back(i);
                    ans.back().push_back(j);
                }
            }
        }
        return ans;
    }
};