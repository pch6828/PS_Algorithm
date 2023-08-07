class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int vl = 0, vr = matrix.size()-1;
        int idx = 0;
        while(vl <= vr){
            int mid = (vl+vr)/2;
            if(matrix[mid][0]>target){
                vr = mid-1;
            }else{
                vl = mid+1;
                idx = max(mid, idx);
            }
        }
        vector<int>& row = matrix[idx];
        auto it = lower_bound(row.begin(), row.end(), target);
        return it != row.end() && *it == target;
    }
};