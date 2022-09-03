class Solution {
private:
    void dfs(vector<int>& ans, int k, int prev, int total, int len){
        if(!len){
            ans.push_back(total);
            return;
        }
        if(prev-k>=0){
            dfs(ans, k, prev-k, total*10+prev-k, len-1);
        }
        if(prev+k<=9&&prev+k!=prev-k){
            dfs(ans, k, prev+k, total*10+prev+k, len-1);
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        for(int i = 1; i <= 9; i++){
            dfs(ans, k, i, i, n-1);
        }
        return ans;
    }
};