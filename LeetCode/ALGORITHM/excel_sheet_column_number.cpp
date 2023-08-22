class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;

        for(int i = 0; i < columnTitle.size(); i++){
            char c = columnTitle[i];
            ans*=26;            
            ans++;
            ans+=(c-'A');
        }

        return ans;
    }
};