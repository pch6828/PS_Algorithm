class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        int ans = -1;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                break;

            if (upper_bound(nums.begin() + i, nums.end(), -nums[i]) -
                lower_bound(nums.begin() + i, nums.end(), -nums[i]))
                return -nums[i];
        }

        return -1;
    }
};