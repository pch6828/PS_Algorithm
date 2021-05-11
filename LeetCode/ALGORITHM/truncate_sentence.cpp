class Solution {
public:
    string truncateSentence(string s, int k) {
        istringstream sin(s);
        string answer;
        
        while(k--){
            string temp;
            sin>>temp;
            answer+=temp;
            answer.push_back(' ');
        }
        answer.pop_back();
        
        return answer;
    }
};