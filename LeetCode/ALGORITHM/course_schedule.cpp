class Solution {
private:
    bool cycle_check(vector<vector<int>>& graph, vector<int>& visited, int cur){
        if(visited[cur]==1){
            return true;
        }else if(visited[cur]==2){
            return false;
        }

        visited[cur] = 1;

        for(int nxt : graph[cur]){
            if(cycle_check(graph, visited, nxt)){
                return true;
            }
        }
        visited[cur] = 2;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>visited(numCourses);

        for(auto& p : prerequisites){
            adj[p[0]].push_back(p[1]);
        }

        for(int i = 0; i < numCourses; i++){
            if(!visited[i] && cycle_check(adj, visited, i)){
                return false;
            }
        }

        return true;
    }
};