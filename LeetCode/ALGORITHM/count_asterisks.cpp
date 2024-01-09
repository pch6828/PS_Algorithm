class Solution
{
public:
    int countAsterisks(string s)
    {
        int cnt = 0;
        bool bar = false;

        for (char c : s)
        {
            if (!bar)
            {
                if (c == '*')
                    cnt++;
                else if (c == '|')
                    bar = true;
            }
            else if (c == '|')
                bar = false;
        }

        return cnt;
    }
};