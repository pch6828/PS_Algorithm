class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>answer;
        map<int, int>cnt;
        
        for(int i : nums){
            cnt[i]++;
        }
        
        answer.push_back(vector<int>());
        for(auto& p : cnt){
            int n = p.first, m = p.second;
            int loop = answer.size();
            for(int i = 0; i < loop; i++){
                for(int j = 0; j < m; j++){
                    answer.push_back(answer[i]);
                    for(int k = 0; k <= j; k++){
                        answer.back().push_back(n);
                    }
                }
            }
        }
        
        return answer;
    }
};