class Solution {
private:
    map<pair<int,int>,double>dp;

    double backtrack(int a, int b){
        if(a <= 0 && b <= 0) return 0.5;
        else if(a <= 0 && b > 0) return 1;
        else if(a > 0 && b <= 0) return 0;
        else if(dp.count({a, b})) return dp[{a, b}];

        return dp[{a, b}] = (backtrack(a-100, b)+backtrack(a-75, b-25)+backtrack(a-50, b-50)+backtrack(a-25, b-75))/4;
    }
public:
    double soupServings(int n) {
        if(n >= 4800) return 1;
        return backtrack(n, n);
    }
};