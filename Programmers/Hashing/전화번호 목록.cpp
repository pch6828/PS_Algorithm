#include <string>
#include <vector>
#include <set>
#include <functional>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    set<string>prefix;
    sort(phone_book.begin(), phone_book.end(), greater<string>());
    for(auto str:phone_book){
        string num = str;
        if(prefix.count(str)){
            answer = false;
            break;
        }
        while(num.size()){
            prefix.insert(num);
            num.pop_back();
        }
    }
    return answer;
}