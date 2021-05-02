class Solution {
public:
    int countPrimes(int n) {
        bool is_prime[5000001] = {true, true, false,};
        int answer = 0;
        for (long long i = 2; i <= sqrt(n); i++){
            if(!is_prime[i]){
                for(long long j = i*i; j < n; j+=i){
                    is_prime[j] = true;
                }
            }
        }
        for(int i = 0; i < n; i++){
            answer+=!is_prime[i];
        }
        return answer;
    }
};