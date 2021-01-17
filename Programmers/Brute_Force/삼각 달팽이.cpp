#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    int dx[] = {1,0,-1};
    int dy[] = {0,1,-1};
    vector<vector<int>>snail(n,vector<int>(n));
    int total = n*(n+1)/2;
    int dir = 0, x = 0, y = 0;
    for(int i = 1; i <=total; i++){
        snail[x][y] = i;
        int tx, ty;
        tx = x+dx[dir];
        ty = y+dy[dir];
        if(tx==n||ty==n||tx<0||ty<0||snail[tx][ty]){
            dir++;
            dir%=3;
            tx = x+dx[dir];
            ty = y+dy[dir];
        }
        x = tx;
        y = ty;
    }
    vector<int> answer;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(snail[i][j]){
                answer.push_back(snail[i][j]);
            }
        }
    }
    return answer;
}