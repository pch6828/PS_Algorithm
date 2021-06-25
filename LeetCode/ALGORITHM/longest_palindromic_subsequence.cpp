class Solution {
private:
    vector<vector<int>>dp;
public:
    int get_palindromic_length(string& s, int i, int j){
        if(i==j){
            return 1;
        }else if(i>j){
            return 0;
        }else if(dp[i][j]){
            return dp[i][j];
        }else if(s[i]==s[j]){
            return dp[i][j] = 2 + get_palindromic_length(s, i+1, j-1);
        }else{
            return dp[i][j] = max(get_palindromic_length(s, i+1, j),get_palindromic_length(s, i, j-1));
        }
    }
    
    int longestPalindromeSubseq(string s) {
        dp.resize(s.size(), vector<int>(s.size()));
        
        return get_palindromic_length(s, 0, s.size()-1);
    }
};