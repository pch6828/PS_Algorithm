#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    string answer;
    do{
        answer.push_back(n%3+'0');
        n/=3;
    }while(n);
    return stoi(answer, nullptr, 3);
}