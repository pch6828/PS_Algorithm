#include <string>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int>s;
    for (auto str : operations) {
        istringstream sin(str);
        string cmd;
        int i;
        sin >> cmd >> i;

        if (cmd == "I") {
            s.insert(i);
        }
        else {
            if (s.size() == 0) {
                continue;
            }
            auto it = s.begin();
            if (i == 1) {
                it = s.end();
                it--;
                s.erase(it);
            }
            else {
                s.erase(it);
            }
        }
    }
    if (s.size()) {
        auto it = s.end();
        it--;
        answer.push_back(*it);
        answer.push_back(*s.begin());
    }
    else {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}