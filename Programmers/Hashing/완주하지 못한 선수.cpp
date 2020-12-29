#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int>names;
    string answer = "";
    for (auto str : completion) {
        names[str]++;
    }
    for (auto str : participant) {
        if (names[str]) {
            names[str]--;
        }
        else {
            answer = str;
        }
    }
    return answer;
}