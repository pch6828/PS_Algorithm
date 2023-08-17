class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        
        vector<vector<int>>ans(n, vector<int>(m));
        queue<pair<pair<int, int>, int>>bfs;

        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[i].size(); j++){
                if(!mat[i][j]){
                    bfs.push({{i, j}, 0});
                }
            }
        }

        while(!bfs.empty()){
            auto p = bfs.front();
            int x = p.first.first;
            int y = p.first.second;
            int dist = p.second;
            
            bfs.pop();
            
            for(int i = 0; i < 4; i++){
                int tx = x+dx[i];
                int ty = y+dy[i];

                if(tx>=0&tx<n&&ty>=0&&ty<m&&mat[tx][ty]==1&&ans[tx][ty]==0){
                    ans[tx][ty] = dist+1;
                    bfs.push({{tx, ty}, ans[tx][ty]});
                }
            }
        }

        return ans;
    }
};