#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string numbers) {
    int is_prime[10000000] = {1,1,0,};
    int cnt[10000000] = {0,};
    for(int i = 2; i < 10000; i++){
        if(is_prime[i]==0){
            for(int j = i*i; j < 10000000; j+=i){
                is_prime[j] = 1;
            }
        }
    }
    int answer = 0;
    sort(numbers.begin(), numbers.end());
    do{
        int num = stoi(numbers);
        while(num){
            if(is_prime[num]==0){
                answer+=!cnt[num];
                cnt[num]++;
            }
            num/=10;
        }
    }while(next_permutation(numbers.begin(), numbers.end()));

    return answer;
}