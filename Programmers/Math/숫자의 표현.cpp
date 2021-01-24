#include <string>
#include <vector>

using namespace std;

int prefix_sum(int n){
    return n*(n+1)/2;
}

int solution(int n) {
    int answer = 0;
    int l = 1, r = 1, sum;
    do{
        sum = prefix_sum(r)-prefix_sum(l-1);
        if(sum==n){
            answer++;
            r++;
            l++;
        }else if(sum<n){
            r++;
        }else{
            l++;
        }
    }while(r<=n);
    return answer;
}