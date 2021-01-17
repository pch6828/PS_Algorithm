#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char>st;
    for(char c : s){
        if(c==')'){
            if(st.empty()){
                return false;
            }
            st.pop();
        }else{
            st.push(c);
        }
    }
    return st.empty();
}