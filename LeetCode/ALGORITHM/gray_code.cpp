class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int>answer;
        answer.push_back(0);
        answer.push_back(1);
        
        for(int i = 1; i < n; i++){
            for(int j = answer.size()-1; j >= 0; j--){
                answer.push_back(answer[j]+(1<<i));
            }
        }
        
        return answer;
    }
};