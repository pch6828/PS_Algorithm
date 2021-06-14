class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int answer = 0;
        
        for(int j = 0; j < strs[0].size(); j++){
            bool flag = false;
            for(int i = 1; i < strs.size(); i++){ 
                if(strs[i][j] < strs[i-1][j]){
                    flag = true;
                    break;
                }
            }
            answer+=flag;
        }
        return answer;
    }
};