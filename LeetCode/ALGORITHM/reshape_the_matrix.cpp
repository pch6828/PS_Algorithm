class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>>answer;
        int cnt = 0;
        
        answer.push_back(vector<int>());
        
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[i].size(); j++){
                if(answer.back().size()==c){
                    answer.push_back(vector<int>());
                }
                answer.back().push_back(mat[i][j]);
                cnt++;
            }
        }
        if(cnt!=r*c){
            return mat;
        }
        return answer;
    }
};