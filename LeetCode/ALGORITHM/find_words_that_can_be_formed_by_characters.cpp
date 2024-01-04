class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        int cnt[26] = {
            0,
        },
            save[26] = {
                0,
            },
            ans = 0;

        for (char c : chars)
        {
            cnt[c - 'a']++;
            save[c - 'a']++;
        }

        for (auto &w : words)
        {
            bool flag = true;
            for (char c : w)
            {
                cnt[c - 'a']--;
                if (cnt[c - 'a'] < 0)
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
                ans += w.size();

            for (int i = 0; i < 26; i++)
                cnt[i] = save[i];
        }

        return ans;
    }
};