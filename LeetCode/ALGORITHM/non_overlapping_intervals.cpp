bool cmp(const vector<int> &a, const vector<int> &b)
{
    if (a[1] == b[1])
    {
        return a[0] > b[0];
    }
    return a[1] < b[1];
}

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int ans = 0, prevend = INT_MIN;
        sort(intervals.begin(), intervals.end(), cmp);

        for (auto &i : intervals)
        {
            if (prevend <= i[0])
            {
                prevend = i[1];
            }
            else
            {
                ans++;
            }
        }

        return ans;
    }
};