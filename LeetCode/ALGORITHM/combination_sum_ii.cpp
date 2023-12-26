class Solution {
private:
    void dfs(vector<int>& nums, vector<int>::iterator idx, vector<int>& comb, 
             int target, int cur, vector<vector<int>>&ans) {
        if(cur == target) {
            ans.push_back(comb);
            return;
        }else if(cur > target) {
            return;
        }

        for(auto i = idx; i != nums.end(); i = upper_bound(i, nums.end(), *i)){
            cur+=*i;
            comb.push_back(*i);
            dfs(nums, i+1, comb, target, cur, ans);
            cur-=*i;
            comb.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>comb;
        sort(candidates.begin(), candidates.end());
        
        dfs(candidates, candidates.begin(), comb, target, 0, ans);

        return ans;
    }
};