#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int answer = 0;
    for(auto c:s){
        if(c=='p'||c=='P'){
            answer++;
        }else if(c=='y'||c=='Y'){
            answer--;
        }
    }

    return !answer;
}