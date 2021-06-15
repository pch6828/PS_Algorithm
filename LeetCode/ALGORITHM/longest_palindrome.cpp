class Solution {
public:
    int longestPalindrome(string s) {
        int answer = 0;
        bool odd = false;
        map<char, int>cnt;
        
        for(char c : s){
            cnt[c]++;
        }
        
        for(auto p : cnt){
            odd |= p.second%2;
            answer += p.second - p.second%2;
        }
        
        return answer + odd;
    }
};