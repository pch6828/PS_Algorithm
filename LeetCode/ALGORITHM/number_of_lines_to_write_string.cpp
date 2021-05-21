class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        vector<int>answer(2);
        
        answer[0]++;
        
        for(char c : s){
            if(answer[1]+widths[c-'a']>100){
                answer[0]++;
                answer[1] = widths[c-'a'];
            }else{
                answer[1]+= widths[c-'a'];
            }
        }
        
        return answer;
    }
};