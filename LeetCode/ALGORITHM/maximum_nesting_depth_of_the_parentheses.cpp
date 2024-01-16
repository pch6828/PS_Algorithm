class Solution
{
public:
    int maxDepth(string s)
    {
        int ans = 0;
        int depth = 0;

        for (char c : s)
        {
            if (c == '(')
                depth++;
            else if (c == ')')
                depth--;

            ans = max(ans, depth);
        }
        return ans;
    }
};