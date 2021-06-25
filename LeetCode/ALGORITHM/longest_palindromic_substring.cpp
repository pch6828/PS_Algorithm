class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        for(int i = n; i > 0; i--){
            for(int j = 0; j <= n - i; j++){
                int a = j;
                int b = j+i-1;
                bool flag = true;
                
                while(flag&&a < b){
                    if(s[a]!=s[b]){
                        flag = false;
                    }
                    a++;
                    b--;
                }
                
                if(flag){
                    return s.substr(j, i);
                }
            }
        }
        return "";
    }
};