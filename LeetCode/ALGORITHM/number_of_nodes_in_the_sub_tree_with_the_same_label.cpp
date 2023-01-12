class Solution {
private:
    vector<vector<int>>adj;
    vector<vector<int>>cntLabel;

    void constructAdjList(int n, vector<vector<int>>& edges){
        adj.resize(n);
        cntLabel.resize(n);

        for(auto& edge : edges){
            int a = edge[0];
            int b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }

    int dfs(int node, string& labels){
        int step = 0;

        cntLabel[node].resize(26);
        cntLabel[node][labels[node]-'a']++;

        for(int nxt : adj[node]){
            if(!cntLabel[nxt].size()){
                dfs(nxt, labels);
                for(int i = 0; i < 26; i++){
                    cntLabel[node][i] += cntLabel[nxt][i];
                }
            }
        }

        return step;
    }

public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int>ans(n);

        constructAdjList(n, edges);
        dfs(0, labels);
        
        for(int i = 0; i < n; i++){
            ans[i] = cntLabel[i][labels[i]-'a'];
        }

        return ans;
    }
};