class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        vector<int> turns;

        for (int i = 0; i < dist.size(); i++)
        {
            turns.push_back(dist[i] / speed[i] + !!(dist[i] % speed[i]));
        }

        sort(turns.begin(), turns.end());

        for (int i = 0; i < turns.size(); i++)
        {
            if (i >= turns[i])
                return i;
        }

        return turns.size();
    }
};