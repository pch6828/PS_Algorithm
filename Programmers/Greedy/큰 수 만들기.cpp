#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char>st;
    for(char c : number){
        while(!st.empty()&&st.top()<c&&k){
            st.pop();
            k--;
        }
        st.push(c);
    }
    while(k){
        st.pop();
        k--;
    }
    while(!st.empty()){
        answer.push_back(st.top());
        st.pop();
    }
    reverse(answer.begin(), answer.end());
    return answer;
}