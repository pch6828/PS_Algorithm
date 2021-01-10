#include <string>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& computers, vector<bool>& visited, int now){
    for(int i = 0; i < computers[now].size(); i++){
        int nxt = i;
        if(computers[now][nxt]&&!visited[nxt]){
            visited[nxt] = true;
            dfs(computers, visited, nxt);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool>visited(n);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            visited[i] = true;
            answer++;
            dfs(computers, visited, i);
        }
    }
    return answer;
}