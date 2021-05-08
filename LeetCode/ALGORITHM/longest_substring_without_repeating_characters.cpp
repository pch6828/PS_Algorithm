class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int answer = min(1, (int)(s.size())), now = 1, cnt[128] = {0,};
        int l = 0, r = 0, n = s.size();
        
        while(r < n){
            if(l==r){
                answer = max(answer, r-l+1);
                cnt[s[r]]++;
                r++;
            }else if(cnt[s[r]]){
                cnt[s[l]]--;
                l++;
            }else{
                answer = max(answer, r-l+1);
                cnt[s[r]]++;
                r++;
            }
        }
        return answer;
    }
};