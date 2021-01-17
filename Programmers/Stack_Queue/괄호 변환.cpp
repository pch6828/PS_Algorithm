#include <string>
#include <vector>
#include <stack>

using namespace std;

bool is_vps(string p){
    stack<char>st;
    for(auto c : p){
        if(c=='('){
            st.push(c);
        }else if(st.empty()){
            return false;
        }else{
            st.pop();
        }
    }
    return st.empty();
}

string solution(string p) {
    string answer;
    if(p==""){
        return "";
    }
    string u, v;
    int cnt = 0, idx = 1;
    u.push_back(p[0]);
    if(p[0]=='('){
        cnt++;
    }else{
        cnt--;
    }
    while(cnt){
        u.push_back(p[idx]);
        if(p[idx]=='('){
            cnt++;
        }else{
            cnt--;
        }
        idx++;
    }
    v = p.substr(idx);
    if(is_vps(u)){
        return u+solution(v);
    }
    answer.push_back('(');
    answer+=solution(v);
    answer.push_back(')');
    u.pop_back();
    u = u.substr(1);
    for(auto&c:u){
        c = (c=='('?')':'(');
    }
    answer+=u;
    
    return answer;
}