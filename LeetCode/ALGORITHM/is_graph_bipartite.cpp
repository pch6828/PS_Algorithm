class Solution
{
private:
    bool dfs(vector<vector<int>> &graph, map<int, int> &color, int node)
    {
        for (int nxt : graph[node])
        {
            if (color.count(nxt))
            {
                if (color[nxt] == color[node])
                {
                    return false;
                }
            }
            else
            {
                color[nxt] = (color[node] + 1) % 2;
                if (!dfs(graph, color, nxt))
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        map<int, int> color;
        for (int i = 0; i < graph.size(); i++)
        {
            if (!color.count(i))
            {
                color[i] = 0;
                if (!dfs(graph, color, i))
                {
                    return false;
                }
            }
        }
        return true;
    }
};