#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    if(num==1){
        return 0;
    }
    long long number = num;
    for(int i = 1; i <= 500; i++){
        if(number%2){
            number*=3;
            number++;
        }else{
            number/=2;
        }
        if(number==1){
            return i;
        }
    }
    return -1;
}