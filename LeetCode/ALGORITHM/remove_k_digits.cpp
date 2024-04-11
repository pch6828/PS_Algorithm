class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        string ans;

        ans.push_back(num[0]);

        for (int i = 1; i < num.size(); i++)
        {
            while (k && !ans.empty() && ans.back() > num[i])
            {
                ans.pop_back();
                k--;
            }
            if (num[i] == '0' && ans.empty())
                continue;
            ans.push_back(num[i]);
        }
        if (k)
        {
            while (k && !ans.empty())
            {
                ans.pop_back();
                k--;
            }
        }
        if (ans.empty())
            ans = "0";
        return ans;
    }
};