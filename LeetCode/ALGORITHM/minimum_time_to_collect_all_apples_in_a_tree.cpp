class Solution {
private:
    vector<vector<int>>adj;
    vector<int>numApples;
    vector<bool>visited;

    void constructAdjList(int n, vector<vector<int>>& edges){
        adj.resize(n);
        visited.resize(n);

        for(auto& edge : edges){
            int a = edge[0];
            int b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }

    int countApplesInSubTree(int node, vector<bool>& hasApple){
        int cnt = hasApple[node];

        visited[node] = true;
        
        for(int nxt : adj[node]){
            if(!visited[nxt]){
                numApples[nxt] = countApplesInSubTree(nxt, hasApple);
                cnt += numApples[nxt];
            }
        }

        return cnt;
    }

    void countApples(int n, vector<bool>& hasApple){
        numApples.resize(n);

        for(int i = 0; i < n; i++){
            visited[i] = false;
        }

        numApples[0] = countApplesInSubTree(0, hasApple);        
        
        for(int i = 0; i < n; i++){
            visited[i] = false;
        }
    }

    int dfs(int node){
        int step = 0;

        visited[node] = true;

        for(int nxt : adj[node]){
            if(numApples[nxt] && !visited[nxt]){
                step += dfs(nxt);
                step += 2;
            }
        }

        return step;
    }

public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        constructAdjList(n, edges);
        countApples(n, hasApple);
        return dfs(0);
    }
};