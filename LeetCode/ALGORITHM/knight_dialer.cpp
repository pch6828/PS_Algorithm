class Solution
{
private:
    int prev[10][3] = {{4, 6, -1}, {6, 8, -1}, {7, 9, -1}, {4, 8, -1}, {3, 9, 0}, {-1, -1, -1}, {1, 7, 0}, {2, 6, -1}, {1, 3, -1}, {2, 4, -1}};
    int mod = 1000000007;

public:
    int knightDialer(int n)
    {
        int ans = 0, dp[2][10];

        for (int i = 0; i < 10; i++)
            dp[1][i] = 1;

        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                dp[i % 2][j] = 0;
                for (int k = 0; k < 3; k++)
                {
                    if (prev[j][k] == -1)
                        break;

                    dp[i % 2][j] += dp[(i - 1) % 2][prev[j][k]];
                    dp[i % 2][j] %= mod;
                }
            }
        }

        for (int i = 0; i < 10; i++)
        {
            ans += dp[n % 2][i];
            ans %= mod;
        }

        return ans;
    }
};