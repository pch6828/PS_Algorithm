#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    string str;
    while(n){
        str.push_back(n%2+'0');
        n/=2;
    }
    str.push_back('0');
    reverse(str.begin(), str.end());
    next_permutation(str.begin(), str.end());
    return stoi(str, nullptr, 2);
}