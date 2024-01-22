class Solution
{
public:
    int minSteps(string s, string t)
    {
        int ans = 0;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for (auto i = t.begin(); i != t.end(); i = upper_bound(i, t.end(), *i))
        {
            ans += max((upper_bound(i, t.end(), *i) - i) - (upper_bound(s.begin(), s.end(), *i) - lower_bound(s.begin(), s.end(), *i)), 0L);
        }

        return ans;
    }
};