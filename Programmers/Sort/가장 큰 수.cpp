#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<pair<string, string>>num;
    for(auto i : numbers){
        string str = to_string(i);
        string mul = str+str+str+str;
        num.push_back({mul, str});
    }
    
    sort(num.begin(), num.end(), greater<pair<string, string>>());
    for(auto s : num){
        answer+=s.second;
    }
    reverse(answer.begin(), answer.end());
    while(answer.size()>1&&answer.back()=='0'){
        answer.pop_back();
    }
    reverse(answer.begin(), answer.end());
    return answer;
}