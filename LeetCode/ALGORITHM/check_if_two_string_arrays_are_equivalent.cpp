class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        int i1, i2, j1, j2;
        i1 = i2 = j1 = j2 = 0;

        while (true)
        {
            if (word1[i1][j1] == word2[i2][j2])
            {
                bool flag = false;
                j1++;
                j2++;

                if (j1 == word1[i1].size())
                {
                    j1 = 0;
                    i1++;
                }
                if (j2 == word2[i2].size())
                {
                    j2 = 0;
                    i2++;
                }
                if (i1 == word1.size() || i2 == word2.size())
                    break;
            }
            else
                return false;
        }

        return i1 == word1.size() && i2 == word2.size();
    }
};