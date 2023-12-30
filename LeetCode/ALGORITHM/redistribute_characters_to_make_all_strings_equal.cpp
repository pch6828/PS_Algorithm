class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int cnt[26] = {0,};
        int target;

        for(auto& s : words){
            for(char c : s){
                cnt[c-'a']++;
                target = cnt[c-'a'];
            }
        }

        for(int i = 0; i < 26; i++){
            if(cnt[i] && cnt[i] % words.size()) return false;
        }
        return true;
    }
};