class Solution {
private:
    vector<string>answer;
public:
    void get_answer(string& s, int idx){
        if(idx==s.size()){
            answer.push_back(s);
            return;
        }
        if('0'<=s[idx]&&s[idx]<='9'){
            get_answer(s, idx+1);
        }else{
            s[idx] -= 32;
            get_answer(s, idx+1);
            s[idx] += 32;
            get_answer(s, idx+1);
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        for(char& c : s){
            if('A'<=c&&c<='Z'){
                c += 32;
            }
        }
        
        get_answer(s, 0);
        
        return answer;
    }
};