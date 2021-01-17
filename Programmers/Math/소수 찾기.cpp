#include <string>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

int solution(int n) {
    int answer = 0;
    int is_prime[1000005] = {0,};
    for(ll i = 2; i <= sqrt(n)+1; i++){
        if(!is_prime[i]){
            for(ll j = i*i; j <= n; j+=i){
                is_prime[j] = 1;
            }
        }
    }
    for(int i = 2; i <=n; i++){
        answer+=!is_prime[i];
    }
    return answer;
}