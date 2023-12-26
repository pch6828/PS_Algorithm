class Solution {
public:
    int maxScore(string s) {
        int zeros[500] = {0,};
        int ans = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i]=='0')
                zeros[i] = 1;
            if(i)
                zeros[i]+=zeros[i-1];
        }
        for(int i = 0; i < s.size() - 1; i++){
            int temp = zeros[i] + s.size() - (i + 1) - (zeros[s.size()-1] - zeros[i]);
            ans = max(ans, temp);
        }
        return ans;
    }
};