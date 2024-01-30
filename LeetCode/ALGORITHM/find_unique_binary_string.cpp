class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        string ans;

        int index = 0;
        for (auto binary : nums)
        {
            ans.push_back('1' - binary[index] + '0');
            index += 1;
        }
        return ans;
    }
};