class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>answer;
        int x = 0, y = 0, dir = 0, n = matrix.front().size(), m = matrix.size();
        
        int dx[] = {0,1, 0,-1};
        int dy[] = {1,0,-1, 0};
        
        for(int i = 1; i <= n*m; i++){
            answer.push_back(matrix[x][y]);
            matrix[x][y] = INT_MAX;
            int tx = x + dx[dir];
            int ty = y + dy[dir];
            
            if(!(tx>=0&&tx<m&&ty>=0&&ty<n&&matrix[tx][ty]!=INT_MAX)){
                dir++;
                dir%=4;
            }
            
            x+=dx[dir];
            y+=dy[dir];
        }
        
        return answer;
    }
};
