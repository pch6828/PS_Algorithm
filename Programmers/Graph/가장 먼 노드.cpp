#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>>adj(n+1);
    vector<int>visit(n+1);
    for(auto e : edge){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    int answer = 0;
    
    queue<int>bfs;
    bfs.push(1);
    visit[1] = 1;
    while(!bfs.empty()){
        int now = bfs.front();
        bfs.pop();
        
        for(int nxt : adj[now]){
            if(visit[nxt]==0){
                visit[nxt] = visit[now]+1;
                bfs.push(nxt);
            }
        }
    }
    
    int dist = *max_element(visit.begin(), visit.end());
    for(int i = 1; i <=n; i++){
        answer+=(visit[i]==dist);
    }
    return answer;
}