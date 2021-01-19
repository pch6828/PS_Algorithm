#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long r = sqrt(n);
    if(r*r==n){
        return (r+1)*(r+1);
    }
    return -1;
}