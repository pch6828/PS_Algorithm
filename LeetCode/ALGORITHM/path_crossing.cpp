class Solution
{
public:
    bool isPathCrossing(string path)
    {
        set<pair<int, int>> points;
        int x = 0, y = 0;

        points.insert({x, y});

        for (char c : path)
        {
            if (c == 'N')
                y++;
            else if (c == 'S')
                y--;
            else if (c == 'E')
                x++;
            else if (c == 'W')
                x--;

            if (points.count({x, y}))
                return true;
            points.insert({x, y});
        }

        return false;
    }
};