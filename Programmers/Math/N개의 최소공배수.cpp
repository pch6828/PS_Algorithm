#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int answer = 1;
    int is_prime[101] = {0,};
    int cnt[101] = {0,};
    for(int i = 2; i <=100; i++){
        if(!is_prime[i]){
            for(int j = i*i; j <=100; j+=i){
                is_prime[j] = 1;
            }
        }
    }
    
    for(int n : arr){
        for(int i = 2; i <= 100; i++){
            int temp_cnt = 0;
            int temp_n = n;
            if(!is_prime[i]){
                while(!(n%i)){
                    n/=i;
                    temp_cnt++;
                }
            }
            cnt[i] = max(cnt[i], temp_cnt);
        }
    }
    for(int i = 2; i <=100; i++){
        if(!is_prime[i]){
            while(cnt[i]){
                answer*=i;
                cnt[i]--;
            }
        }
    }
    
    return answer;
}