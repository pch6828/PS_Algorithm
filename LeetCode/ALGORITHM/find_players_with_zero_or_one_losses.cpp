class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        vector<vector<int>> ans(2);
        set<int> no_loss, one_loss, more_loss;

        for (auto &m : matches)
        {
            int winner = m[0], loser = m[1];

            if (!(more_loss.count(winner) || one_loss.count(winner)))
                no_loss.insert(winner);

            if (no_loss.count(loser))
            {
                one_loss.insert(loser);
                no_loss.erase(loser);
            }
            else if (one_loss.count(loser))
            {
                more_loss.insert(loser);
                one_loss.erase(loser);
            }
            else if (!more_loss.count(loser))
                one_loss.insert(loser);
        }

        for (int i : no_loss)
            ans[0].push_back(i);

        for (int i : one_loss)
            ans[1].push_back(i);

        return ans;
    }
};