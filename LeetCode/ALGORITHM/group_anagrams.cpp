class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        map<string, int>idx;
        for(string& s : strs){
            string temp = s;
            sort(temp.begin(), temp.end());

            if(!idx.count(temp)){
                idx[temp] = ans.size();
                ans.emplace_back();
            }
            ans[idx[temp]].push_back(s);
        }
        return ans;
    }
};