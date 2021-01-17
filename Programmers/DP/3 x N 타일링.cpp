#include <string>
#include <vector>

using namespace std;

typedef long long ll;

int solution(int n) {
    ll dp[5001] = {0,};
    if(n%2){
        return 0;
    }
    n/=2;
    dp[0] = 1;
    for(int i = 1; i <=n; i++){
        dp[i] = dp[i-1]*3;
        dp[i] %= 1000000007;
        for(int j = 2; j <=i; j++){
            dp[i] += dp[i-j]*2;
            dp[i] %= 1000000007;
        }
    }
    return dp[n];
}