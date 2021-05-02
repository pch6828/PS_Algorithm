class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int idx, int x, int y){
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        int n = board.size();
        int m = board[0].size();
        if(idx==word.size()){
            return true;
        }
        for(int i = 0; i < 4; i++){
            int tx = x+dx[i];
            int ty = y+dy[i];
            if(tx>=0&&tx<n&&ty>=0&&ty<m&&board[tx][ty]==word[idx]){
                board[tx][ty] = ' ';
                if(dfs(board, word, idx+1, tx, ty)){
                    return true;
                }
                board[tx][ty] = word[idx];
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] == word[0]){
                    board[i][j] = ' ';
                    if(dfs(board, word, 1, i, j)){
                        return true;   
                    }
                    board[i][j] = word[0];
                }
            }
        }
        
        return false;
    }
};