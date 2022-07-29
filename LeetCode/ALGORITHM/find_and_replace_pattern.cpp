class Solution {
private:
    bool is_same_pattern(string& a, string b){
        char match[26] = {0,};
        bool is_used[26] = {false, };
        
        for(int i = 0; i < b.size(); i++){
            if(!match[b[i]-'a'] && !is_used[a[i]-'a']){
                match[b[i]-'a'] = a[i];
                is_used[a[i]-'a'] = true;
            }else if(!match[b[i]-'a'] && is_used[a[i]-'a']){
                return false;
            }else if(match[b[i]-'a']!=a[i]){
                return false;
            }
        }
        return true;
    }
    
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        
        for(string& word : words){
            if(is_same_pattern(word, pattern)){
                ans.push_back(word);
            }
        }
        
        return ans;
    }
};