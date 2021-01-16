#include <vector>
#include <queue>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int dx[] = {0,0,-1,1};
    int dy[] = {1,-1,0,0};
    queue<pair<int, int>>bfs;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(picture[i][j]){
                number_of_area++;
                int size = 0;
                int color = picture[i][j];
                picture[i][j] = 0;
                bfs.push({i,j});
                while(!bfs.empty()){
                    auto now = bfs.front();
                    bfs.pop();
                    size++;
                    for(int k = 0; k < 4; k++){
                        int tx = now.first+dx[k];
                        int ty = now.second+dy[k];
                        if(tx>=0&&tx<m&&ty>=0&&ty<n&&picture[tx][ty]==color){
                            picture[tx][ty] = 0;
                            bfs.push({tx, ty});
                        }
                    }
                }
                max_size_of_one_area = max(max_size_of_one_area,size);
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}