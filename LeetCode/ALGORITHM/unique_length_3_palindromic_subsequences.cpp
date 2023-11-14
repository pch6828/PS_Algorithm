class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int first[26], last[26];
        int cnt[100001][26] = {0,};
        int ans = 0;

        for(int i = 0; i < 26; i++){
            first[i] = last[i] = -1;
        }
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(first[c-'a']==-1){
                first[c-'a'] = i;
            }else{
                last[c-'a'] = i;
            }
            for(int j = 0; j < 26; j++){
                if(i)
                    cnt[i][j]+=cnt[i-1][j];
            }
            cnt[i][c-'a']++;
        }

        for(int i = 0; i < 26; i++){
            if(first[i]!=-1 && last[i]!=-1){
                for(int j = 0; j < 26; j++){
                    if(cnt[last[i]-1][j] - cnt[first[i]][j] > 0){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};