class Solution
{
public:
    int countKDifference(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int ans = 0;

        for (auto it = nums.begin(); it != nums.end(); it = upper_bound(it, nums.end(), *it))
        {
            int n = *it;
            int cnt = upper_bound(nums.begin(), nums.end(), *it) - it;

            ans += cnt * (upper_bound(it, nums.end(), *it + k) - lower_bound(it, nums.end(), *it + k));
        }

        return ans;
    }
};