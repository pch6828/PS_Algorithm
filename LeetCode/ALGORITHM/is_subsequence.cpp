class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx = 0, n = t.size();
        
        for(char c : s){
            bool flag = true;
            
            while(idx < n && (flag = t[idx++]!=c));
            
            if(flag){
                return false;
            }
        }
        
        return true;
    }
};