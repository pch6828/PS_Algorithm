class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int dp[100] = {
            0,
        },
            ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            switch (i)
            {
            case 0:
                dp[i] = nums[i];
                break;
            case 1:
                dp[i] = nums[i];
                break;
            case 2:
                dp[i] = nums[i] + nums[i - 2];
                break;
            default:
                dp[i] = max(nums[i] + dp[i - 2], nums[i] + dp[i - 3]);
                break;
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};