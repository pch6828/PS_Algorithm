class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int cnt = 0;

        for (int i = 0; i < s.size(); i++)
        {
            for (char c : vowels)
            {
                if (s[i] == c)
                {
                    cnt += (i < s.size() / 2 ? 1 : -1);
                    break;
                }
            }
        }

        return !cnt;
    }
};