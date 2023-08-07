class Solution
{
private:
    bool isDigits(string &s, int a, int b)
    {
        if (a > b)
            return false;

        for (int i = a; i <= b; i++)
        {
            if (!(s[i] >= '0' && s[i] <= '9'))
                return false;
        }
        return true;
    }
    bool isInteger(string &s, int a, int b)
    {
        if (s[a] == '+' || s[a] == '-')
            a++;
        if (a > b)
            return false;

        return isDigits(s, a, b);
    }
    bool isDecimal(string &s, int a, int b)
    {
        if (s[a] == '+' || s[a] == '-')
            a++;
        if (a > b)
            return false;

        int dot_idx = -1;

        for (int i = a; i <= b; i++)
        {
            if (s[i] == '.')
            {
                dot_idx = i;
                break;
            }
        }
        if (dot_idx == a)
        {
            return isDigits(s, a + 1, b);
        }
        else if (dot_idx == b)
        {
            return isDigits(s, a, b - 1);
        }
        else
        {
            return isDigits(s, a, dot_idx - 1) && isDigits(s, dot_idx + 1, b);
        }
    }

public:
    bool isNumber(string s)
    {
        int e_idx = -1;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'e' || s[i] == 'E')
            {
                e_idx = i;
                break;
            }
        }

        if (e_idx == -1)
        {
            return isDecimal(s, 0, s.size() - 1) || isInteger(s, 0, s.size() - 1);
        }
        else
        {
            return (isDecimal(s, 0, e_idx - 1) || isInteger(s, 0, e_idx - 1)) && isInteger(s, e_idx + 1, s.size() - 1);
        }
    }
};