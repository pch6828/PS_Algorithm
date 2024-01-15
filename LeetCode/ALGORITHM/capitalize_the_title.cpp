class Solution
{
public:
    string capitalizeTitle(string title)
    {
        bool flag = true;

        for (int i = 0; i < title.size(); i++)
        {
            if (title[i] == ' ')
            {
                flag = true;
                continue;
            }

            if (flag)
            {
                title[i] |= 32;
                if (!(i + 1 == title.size() || title[i + 1] == ' ' || i + 2 == title.size() || title[i + 2] == ' '))
                    title[i] -= 32;
            }
            else
            {
                title[i] |= 32;
            }
            flag = false;
        }
        return title;
    }
};