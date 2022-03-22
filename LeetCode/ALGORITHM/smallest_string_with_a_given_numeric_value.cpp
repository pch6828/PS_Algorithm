class Solution
{
private:
    bool canMakeString(int n, int k)
    {
        return n * 26 > k;
    }

public:
    string getSmallestString(int n, int k)
    {
        string ans;
        while (canMakeString(n - 1, k - 1))
        {
            ans.push_back('a');
            n--;
            k--;
        }
        if (k % 26)
        {
            ans.push_back('a' + k % 26 - 1);
            k -= k % 26;
        }
        while (k)
        {
            ans.push_back('z');
            k -= 26;
        }
        return ans;
    }
};