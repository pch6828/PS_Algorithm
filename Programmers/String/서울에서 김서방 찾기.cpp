#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    string head = "김서방은 ", tail = "에 있다";
    return head+to_string(find(seoul.begin(), seoul.end(), "Kim")-seoul.begin())+tail;
}