class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int l = 0, r = citations.size();
        int ans = 0;

        while (l <= r)
        {
            int mid = (l + r) / 2;
            int cnt = 0;

            for (int cite : citations)
            {
                cnt += cite >= mid;
            }

            if (cnt >= mid)
            {
                l = mid + 1;
                ans = max(ans, mid);
            }
            else
            {
                r = mid - 1;
            }
        }

        return ans;
    }
};