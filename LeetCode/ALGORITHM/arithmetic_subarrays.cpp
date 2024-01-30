class Solution
{
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        vector<bool> ans;

        for (int i = 0; i < l.size(); i++)
        {
            int l_idx = l[i], r_idx = r[i];
            vector<int> temp(nums.begin() + l_idx, nums.begin() + r_idx + 1);
            bool flag = true;

            sort(temp.begin(), temp.end());

            for (int j = 2; j < temp.size(); j++)
            {
                if (temp[j] - temp[j - 1] != temp[j - 1] - temp[j - 2])
                {
                    flag = false;
                    break;
                }
            }
            ans.push_back(flag);
        }

        return ans;
    }
};