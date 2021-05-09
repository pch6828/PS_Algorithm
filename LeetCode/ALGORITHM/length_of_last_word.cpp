class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream sin(s);
        
        string str;
        int answer = 0;
        while(sin>>str){
            answer = str.size();
        }
        return answer;
    }
};