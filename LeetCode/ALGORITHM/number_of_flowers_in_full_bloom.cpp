class Solution
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people)
    {
        vector<int> startTime, endTime, ans;

        for (auto &p : flowers)
        {
            startTime.push_back(p[0]);
            endTime.push_back(p[1]);
        }

        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());

        for (int p : people)
        {
            int cnt = flowers.size();

            cnt -= startTime.end() - lower_bound(startTime.begin(), startTime.end(), p + 1);
            cnt -= lower_bound(endTime.begin(), endTime.end(), p) - endTime.begin();

            ans.push_back(cnt);
        }

        return ans;
    }
};