class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        vector<int> ans(2);
        int prev = 0;
        sort(nums.begin(), nums.end());

        for (int i : nums)
        {
            if (prev == i)
            {
                ans[0] = i;
            }
            else if (i - prev == 2)
            {
                ans[1] = prev + 1;
            }
            prev = i;
        }
        if (ans[1] == 0)
        {
            ans[1] = nums.size();
        }
        return ans;
    }
};