class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int ans;
        vector<int>idx(n);
        while(k--){
            ans = INT_MAX;
            int row = 0;
            for(int i = 0; i < n; i++){
                if(idx[i] < n && ans > matrix[i][idx[i]]){
                    row = i;
                    ans = matrix[i][idx[i]];
                }
            }
            idx[row]++;
        }
        return ans;
    }
};