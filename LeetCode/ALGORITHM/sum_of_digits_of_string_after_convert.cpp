class Solution
{
public:
    int getLucky(string s, int k)
    {
        int ans = 0;

        for (char c : s)
        {
            int t = c - 'a' + 1;
            while (t)
            {
                ans += t % 10;
                t /= 10;
            }
        }
        k--;

        while (k--)
        {
            int t = 0;
            while (ans)
            {
                t += ans % 10;
                ans /= 10;
            }
            ans = t;
        }

        return ans;
    }
};