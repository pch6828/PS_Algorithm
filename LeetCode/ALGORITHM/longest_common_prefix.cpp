class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string answer;
        string a = strs.back();
        strs.pop_back();
        
        int n = a.size();
        
        for(int i = 0; i < n; i++){
            char c = a[i];
            bool flag = true;
            for(auto& s : strs){
                if(s.size() < i){
                    flag = false;
                    break;
                }else if(s[i]!=c){
                    flag = false;
                    break;
                }
            }
            if(!flag){
                break;
            }
            answer.push_back(c);
        }
        
        return answer;
    }
};