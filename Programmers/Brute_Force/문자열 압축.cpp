#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.size();
    int len = s.size();
    for (int i = 1; i < len; i++) {
        int cnt = 1;
        int idx = 0;
        string result;
        string prev;
        string temp;
        bool flag = false;
        while (idx < len) {
            temp.push_back(s[idx]);
            idx++;
            if (idx % i==0) {
                if (prev == temp) {
                    cnt++;
                }
                else {
                    if (cnt > 1) {
                        result += to_string(cnt);
                    }
                    cnt = 1;
                    result += prev;
                    prev = temp;
                }
                temp.clear();
            }
        }
        if (cnt > 1) {
                result += to_string(cnt);
            }
        cnt = 1;
        result += prev;
        answer = min(answer, (int)result.size() + (int)temp.size());
    }
    return answer;
}