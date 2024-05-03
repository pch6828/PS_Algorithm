class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int idx1 = 0, idx2 = 0;

        while (true)
        {
            int a = 0, b = 0;

            if (idx1 >= version1.size() && idx2 >= version2.size())
                break;

            for (idx1; idx1 < version1.size(); idx1++)
            {
                if (version1[idx1] == '.')
                {
                    idx1++;
                    break;
                }
                a *= 10;
                a += version1[idx1] - '0';
            }
            for (idx2; idx2 < version2.size(); idx2++)
            {
                if (version2[idx2] == '.')
                {
                    idx2++;
                    break;
                }
                b *= 10;
                b += version2[idx2] - '0';
            }
            if (a > b)
                return 1;
            else if (a < b)
                return -1;
        }

        return 0;
    }
};