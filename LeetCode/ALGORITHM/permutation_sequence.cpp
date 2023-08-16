class Solution
{
public:
    string getPermutation(int n, int k)
    {
        string ans;
        for (int i = 1; i <= n; i++)
        {
            ans.push_back('0' + i);
        }

        for (int i = 1; i < k; i++)
        {
            next_permutation(ans.begin(), ans.end());
        }

        return ans;
    }
};