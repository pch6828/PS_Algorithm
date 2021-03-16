#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool newword = true;
    for(char c : s){
        if(c==' '){
            newword = true;
        }else if(newword){
            if('a'<=c&&c<='z'){
                c -=32;
            }
            newword = false;
        }else{
            if('A'<=c&&c<='Z'){
                c +=32;
            }
        }
        answer.push_back(c);
    }
    return answer;
}