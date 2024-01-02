class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>>ans;
        int prev = -1, idx = 0;
        sort(nums.begin(), nums.end());

        for(int i : nums){
            if(i != prev)
                idx = 0;
            if(idx == ans.size())
                ans.emplace_back();

            ans[idx].push_back(i);    
            idx++;
            prev = i;
        }   

        return ans;
    }
};