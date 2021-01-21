#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int t = x, s = 0;
    while(t){
        s+=t%10;
        t/=10;
    }
    return x%s==0;
}