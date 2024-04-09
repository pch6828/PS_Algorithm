class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        queue<pair<int, int>> line;
        int ans = 0;
        for (int i = 0; i < tickets.size(); i++)
        {
            line.push({i, tickets[i]});
        }

        while (true)
        {
            pair<int, int> p = line.front();
            line.pop();

            p.second--;
            ans++;
            if (p.second)
                line.push(p);
            else if (p.first == k)
                return ans;
        }

        return 0;
    }
};