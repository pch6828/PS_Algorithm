#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <climits>

using namespace std;

string solution(string s) {
    string answer = "";
    int maximum = INT_MIN, minimum = INT_MAX;
    int t;
    istringstream sin(s);
    while(sin>>t){
        maximum = max(maximum,t);
        minimum = min(minimum,t);
    }
    answer = to_string(minimum)+" "+to_string(maximum);
    return answer;
}