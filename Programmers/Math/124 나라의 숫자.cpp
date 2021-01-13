#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    while(n){
        int t = n%3;
        n/=3;
        if(!t){
            n--;
            t = 4;
        }
        answer.push_back(t+'0');
    }
    reverse(answer.begin(), answer.end());
    return answer;
}