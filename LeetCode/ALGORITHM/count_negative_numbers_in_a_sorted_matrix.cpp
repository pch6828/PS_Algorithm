class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int answer = 0;
        for(auto& row : grid){
            answer += lower_bound(row.rbegin(), row.rend(), 0) - row.rbegin();
        }
        return answer;
    }
};