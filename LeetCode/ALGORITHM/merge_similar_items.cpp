class Solution
{
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2)
    {
        map<int, int> item;
        vector<vector<int>> ans;

        for (auto &i : items1)
        {
            item[i[0]] += i[1];
        }
        for (auto &i : items2)
        {
            item[i[0]] += i[1];
        }

        for (auto &p : item)
        {
            ans.emplace_back();
            ans.back().push_back(p.first);
            ans.back().push_back(p.second);
        }

        return ans;
    }
};