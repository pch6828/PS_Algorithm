#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int idx = 0;
    string answer = "";
    for(char c: s){
        if(c==' '){
            idx = 0;   
        }else{
            c &= ~32;
            if(idx%2){
                c+=32;
            }
            idx++;
        }
        answer.push_back(c);
    }
    return answer;
}