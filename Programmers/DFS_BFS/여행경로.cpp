#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> answer;
map<pair<string, string>,int>used;

bool dfs(map<string, vector<string>>&adj, int target, string now){
    answer.push_back(now);
    if(answer.size()==target){
        return true;
    }
    for(string& nxt : adj[now]){
        if(used[{now, nxt}]){
            used[{now, nxt}]--;
            if(dfs(adj, target, nxt)){
                return true;
            }
            used[{now, nxt}]++;
        }
    }
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    map<string, vector<string>>adj;
    for(auto edge : tickets){
        adj[edge[0]].push_back(edge[1]);
        used[{edge[0], edge[1]}]++;
    }
    for(auto& p : adj){
        sort(p.second.begin(), p.second.end());
    }
    dfs(adj, tickets.size()+1, "ICN");
    return answer;
}