class Solution {
private:
    vector<vector<int>>answer;
public:
    void dfs(int idx, int target, vector<int>&num, vector<int>&now){
        if(target == 0){
            answer.push_back(now);
            return;
        }else if(target < 0){
            return;
        }else if(idx == num.size()){
            return;
        }
        now.push_back(num[idx]);
        dfs(idx, target-num[idx], num, now);
        now.pop_back();
        dfs(idx+1, target, num, now);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>track;
        
        dfs(0, target, candidates, track);
        
        return answer;
    }
};