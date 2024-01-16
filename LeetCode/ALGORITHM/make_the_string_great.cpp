class Solution
{
public:
    string makeGood(string s)
    {
        string ans;

        for (char c : s)
        {
            if (ans.empty() || (ans.back() ^ c) != 32)
                ans.push_back(c);
            else
                ans.pop_back();
        }

        return ans;
    }
};