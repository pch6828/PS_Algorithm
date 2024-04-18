class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int ans1 = 0, ans2 = 0;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    int tx = i + dx[k];
                    int ty = j + dy[k];

                    if (tx >= 0 && tx < grid.size() && ty >= 0 && ty < grid[i].size())
                    {
                        if (grid[tx][ty] != grid[i][j])
                            ans1++;
                    }
                    else if (grid[i][j])
                        ans2++;
                }
            }
        }

        return ans1 / 2 + ans2;
    }
};