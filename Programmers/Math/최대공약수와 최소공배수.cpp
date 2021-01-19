#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b){
    if(a%b==0){
        return b;
    }
    return gcd(b, a%b);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    int g = gcd(n,m);
    answer.push_back(g);
    answer.push_back((long long)n*m/g);
    return answer;
}