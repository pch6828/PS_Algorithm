class Solution {
public:
    string generateTheString(int n) {
        string answer(n, 'a');
        
        if(n%2==0){
            answer.pop_back();
            answer.push_back('b');
        }
        
        return answer;
    }
};