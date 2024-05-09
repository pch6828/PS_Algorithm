class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        int cnt = 0;
        long long ans = 0;
        sort(happiness.begin(), happiness.end(), greater<int>());

        while (k--)
        {
            ans += max(happiness[cnt] - cnt, 0);
            cnt++;
        }

        return ans;
    }
};