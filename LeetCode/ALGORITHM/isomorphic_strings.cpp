class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char map1[128] = {0,};
        char map2[128] = {0,};
        int n = s.size();
        
        for(int i = 0; i < n; i++){
            if(!map1[s[i]]){
                map1[s[i]] = t[i];
            }
            if(!map2[t[i]]){
                map2[t[i]] = s[i];
            }
            if(map1[s[i]]!=t[i]||map2[t[i]]!=s[i]){
                return false;
            }
        }
        
        return true;
    }
};