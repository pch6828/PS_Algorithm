class Solution {
public:
    string reverseWords(string s) {
        string ans;
        string temp;

        s.push_back(' ');
        for(char c : s){
            if(c==' '){
                if(!temp.empty()){
                    ans = temp + " " + ans;
                    temp.clear();
                }
                continue;
            }
            temp.push_back(c);
        }
        
        ans.pop_back();
        return ans;
    }
};