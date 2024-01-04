class Solution
{
public:
    int numDecodings(string s)
    {
        int dp[100] = {
            0,
        };

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '0')
            {
                dp[i] = (i ? dp[i - 1] : 1);
            }
            if (i)
            {
                if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6'))
                    dp[i] += (i > 1 ? dp[i - 2] : 1);
            }
        }

        return dp[s.size() - 1];
    }
};