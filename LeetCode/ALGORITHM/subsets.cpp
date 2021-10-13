class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>answer;
        
        answer.push_back(vector<int>());
        
        for(int n : nums){
            int loop = answer.size();
            
            for(int i = 0; i < loop; i++){
                answer.push_back(answer[i]);
                answer.back().push_back(n);
            }
        }
        
        return answer;
    }
};