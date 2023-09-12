class Solution {
public:
    int minDeletions(string s) {
        set<int>unique_freq;
        int cnt[26] = {0,}, ans = 0;

        for(char c : s){
            cnt[c-'a']++;
        }

        for(int i = 0; i < 26; i++){
            while(cnt[i] > 0 && unique_freq.count(cnt[i])){
                cnt[i]--;
                ans++;
            }
            unique_freq.insert(cnt[i]);
        }
        
        return ans;
    }
};