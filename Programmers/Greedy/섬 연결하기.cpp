#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

typedef pair<int, pair<int, int>> Edge;

vector<int>root;

int Find(int now){
    if(root[now]==now){
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

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for(int i = 0; i < n; i++){
        root.push_back(i);
    }
    priority_queue<Edge, vector<Edge>, greater<Edge>>pq;
    for(auto e : costs){
        pq.push({e[2], {e[0], e[1]}});
    }
    
    while(!pq.empty()){
        Edge e = pq.top();
        pq.pop();
        if(Union(e.second.first, e.second.second)){
            answer+=e.first;
        }
    }
    return answer;
}