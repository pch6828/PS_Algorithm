#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int field[301][301], root[90001];
int cnt = 0;
vector<pair<int, pair<int, int>>>edges;
map<pair<int, int>, int>weight;

bool is_in(int x, int y, int n){
    return x>=0&&x<n&&y>=0&&y<n;
}

void get_edge(vector<vector<int>>&land, int height){
    queue<pair<int, int>>bfs;
    for (int i = 0; i < land.size(); i++) {
        for (int j = 0; j < land.size(); j++) {
            if (!field[i][j]) {
                cnt++;
                root[cnt] = cnt;
                field[i][j] = cnt;
                bfs.push({ i,j });
                while (!bfs.empty()) {
                    auto now = bfs.front();
                    bfs.pop();
                    for (int k = 0; k < 4; k++) {
                        int tx = now.first + dx[k];
                        int ty = now.second + dy[k];
                        if (is_in(tx, ty, land.size()) && !field[tx][ty] && abs(land[now.first][now.second] - land[tx][ty]) <= height) {
                            field[tx][ty] = cnt;
                            bfs.push({ tx, ty });
                        }
                        else if (is_in(tx, ty, land.size()) && field[tx][ty]) {
                            int prev = weight[{field[tx][ty], cnt}];
                            if (!prev || prev > abs(land[now.first][now.second] - land[tx][ty])) {
                                weight[{field[tx][ty], cnt}] = abs(land[now.first][now.second] - land[tx][ty]);
                                weight[{cnt, field[tx][ty]}] = abs(land[now.first][now.second] - land[tx][ty]);
                            }
                        }
                    }
                }
            }
        }
    }

    for(auto p:weight){
        edges.push_back({p.second, p.first});
    }
}

int Find(int now){
    if(now==root[now]){
        return now;
    }
    return root[now] = Find(root[now]);
}

bool Union(int a, int b){
    int ra = Find(a), rb = Find(b);
    if(ra==rb){
        return false;
    }
    root[ra] = rb;
    return true;
}

int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    get_edge(land, height);
    
    sort(edges.begin(), edges.end());
    
    for(auto e : edges){
        if(Union(e.second.first, e.second.second)){
            answer+=e.first;
        }
    }
    return answer;
}