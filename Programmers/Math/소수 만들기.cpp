#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    int is_prime[5000] = {0,};
    is_prime[0] = is_prime[1] = 1;
    for(int i = 2; i < 5000; i++){
        if(is_prime[i]==0){
            for(int j = i*i; j < 5000; j+=i){
                is_prime[j] = 1;
            }
        }
    }
    for(int i = 0; i < nums.size(); i++){
        for(int j = i+1; j < nums.size(); j++){
            for(int k = j+1; k <nums.size(); k++){
                answer+=!is_prime[(nums[i]+nums[j]+nums[k])];
            }
        }
    }
    return answer;
}