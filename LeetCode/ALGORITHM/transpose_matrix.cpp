class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>>answer(matrix[0].size(), vector<int>(matrix.size()));
        
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                answer[j][i] = matrix[i][j];
            }
        }
        
        return answer;
    }
};