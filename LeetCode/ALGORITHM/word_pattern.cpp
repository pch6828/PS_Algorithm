class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream sin(s);
        string word;
        map<string, char>p;
        bool used[26] = {false,};
        int idx = 0;
        
        while(sin>>word){
            if(idx==pattern.size()){
                return false;
            }
            if(!p.count(word)){
                if(used[pattern[idx]-'a']){
                    return false;
                }
                p[word] = pattern[idx];
                used[pattern[idx]-'a'] = true;
            }
            
            if(p[word]!=pattern[idx]){
                return false;
            }
            
            idx++;
        }
        
        return idx==pattern.size();
    }
};