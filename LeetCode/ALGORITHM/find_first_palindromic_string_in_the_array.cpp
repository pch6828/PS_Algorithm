class Solution
{
public:
    string firstPalindrome(vector<string> &words)
    {
        for (string &w : words)
        {
            int half = w.size() / 2;
            bool flag = true;
            for (int i = 0; i < half; i++)
            {
                if (w[i] != w[w.size() - i - 1])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return w;
        }

        return "";
    }
};