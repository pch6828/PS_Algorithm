#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int pop_board(int m, int n, vector<string>& board){
    vector<vector<bool>>mark(m, vector<bool>(n));
    int result = 0;
    for(int i = 0; i < m-1; i++){
        for(int j = 0; j < n-1; j++){
            char a = board[i][j];
            char b = board[i+1][j];
            char c = board[i][j+1];
            char d = board[i+1][j+1];
            if(a!=' '&&a==b&&b==c&&c==d){
                mark[i][j] = mark[i+1][j] = mark[i+1][j+1] = mark[i][j+1] = true;
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(mark[i][j]){
                board[i][j] = ' ';
                result++;
            }
        }
    } 
    return result;
}

void fall_down(int m, int n, vector<string>& board){
    for(int i = 0; i < m-1; i++){
        for(int j = 0; j < n; j++){
            if(board[i+1][j]==' '){
                for(int k = i; k >= 0; k--){
                    swap(board[k+1][j],board[k][j]);
                }
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int t = 0;
    while(t = pop_board(m,n,board)){
        answer+=t;
        fall_down(m,n,board);
    }
    return answer;
}