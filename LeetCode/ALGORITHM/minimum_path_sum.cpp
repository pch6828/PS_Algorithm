class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        int now_x = 0, now_y = 0, now_dist, n = grid.size(), m = grid[0].size();
        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
        int dx[] = {0,1};
        int dy[] = {1,0};
        
        pq.push({grid[now_x][now_y], {now_x, now_y}});
        dist[now_x][now_y] = grid[now_x][now_y];
        while(!pq.empty()){
            auto now = pq.top();
            pq.pop();
            
            now_dist = now.first;
            now_x = now.second.first;
            now_y = now.second.second;
            
            if(dist[now_x][now_y]<now_dist){
                continue;
            }
            
            if(now_x==n-1&&now_y==m-1){
                return now_dist;
            }
            
            for(int i = 0; i < 2; i++){
                int tx = now_x + dx[i];
                int ty = now_y + dy[i];
                
                if(tx>=0&&tx<n&&ty>=0&&ty<m&&dist[tx][ty]>now_dist+grid[tx][ty]){
                    dist[tx][ty] = now_dist+grid[tx][ty];
                    pq.push({dist[tx][ty], {tx, ty}});
                }
            }
        }
        
        return -1;
    }
};