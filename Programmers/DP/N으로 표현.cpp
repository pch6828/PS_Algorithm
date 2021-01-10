#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {
    vector<set<int>>dp(9);
    
    int t = 0;
    for(int i = 1; i <= 8; i++){
        t = t*10+N;
        dp[i].insert(t);
    }
    
    for(int i = 1; i <=8; i++){
        for(int j = 1; j < i; j++){
            for(int a : dp[j]){
                for(int b : dp[i - j]){
                    dp[i].insert(a+b);
                    dp[i].insert(a-b);
                    dp[i].insert(a*b);
                    if(b){
                        dp[i].insert(a/b);
                    }
                }
            }
        }
        if(dp[i].count(number)){
            return i;
        }
    }
    return -1;
}