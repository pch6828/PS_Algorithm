#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(auto c : s){
        if(c>='a'&&c<='z'){
            int i = (c-'a'+n)%26;
            answer.push_back(i+'a');
        }else if(c>='A'&&c<='Z'){
            int i = (c-'A'+n)%26;
            answer.push_back(i+'A');
        }else{
            answer.push_back(c);
        }
    }
    return answer;
}