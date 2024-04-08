class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ans = 0, len = nums.size() / 2;

        for (int i = 0; i < len; i++)
        {
            ans = max(ans, nums[i] + nums[nums.size() - 1 - i]);
        }

        return ans;
    }
};