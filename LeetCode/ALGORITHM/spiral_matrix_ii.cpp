class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>answer(n, vector<int>(n));
        
        int x = 0, y = 0, dir = 0;
        
        int dx[] = {0,1, 0,-1};
        int dy[] = {1,0,-1, 0};
        
        for(int i = 1; i <= n*n; i++){
            answer[x][y] = i;
            
            int tx = x + dx[dir];
            int ty = y + dy[dir];
            
            if(!(tx>=0&&tx<n&&ty>=0&&ty<n&&answer[tx][ty]==0)){
                dir++;
                dir%=4;
            }
            
            x+=dx[dir];
            y+=dy[dir];
        }
        
        return answer;
    }
};