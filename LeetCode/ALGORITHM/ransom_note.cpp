class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[26] = {0,};
        for(char c : magazine){
            cnt[c-'a']++;
        }
        for(char c : ransomNote){
            if(cnt[c-'a']){
                cnt[c-'a']--;
            }else{
                return false;
            }
        }
        return true;
    }
};