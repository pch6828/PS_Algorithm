class Solution {
public:
    string removeDuplicates(string s) {
        string answer;
        
        for(auto c : s){
            if(answer.empty()||answer.back()!=c){
                answer.push_back(c);
            }else{
                answer.pop_back();
            }
        }
        
        return answer;
    }
};