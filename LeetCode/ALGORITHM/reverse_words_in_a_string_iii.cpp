class Solution {
public:
    string reverseWords(string s) {
        string answer;
        istringstream sin(s);
        string temp;
        while(sin >> temp){
            reverse(temp.begin(), temp.end());
            answer += temp;
            answer.push_back(' ');
        }
        answer.pop_back();
        return answer;
    }
};