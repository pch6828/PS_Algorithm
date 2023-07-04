class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        map<int, int> cnt;

        for (int i : nums)
        {
            cnt[i]++;
        }

        for (auto p : cnt)
        {
            if (p.second == 1)
            {
                return p.first;
            }
        }
        return 0;
    }
};

class Solution2
{
public:
    int singleNumber(vector<int> &nums)
    {
        int cnt[32] = {
            0,
        },
            ans = 0;
        unsigned unit = 1;

        for (int i : nums)
        {
            for (int j = 0; j < 32; j++)
            {
                cnt[j] += i & 1;
                i >>= 1;
            }
        }

        for (int i = 0; i < 32; i++)
        {
            if (cnt[i] % 3)
            {
                ans += unit;
            }
            unit *= 2;
        }
        return ans;
    }
};