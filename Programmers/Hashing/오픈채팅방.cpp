#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string>nickname;
    for(string log : record){
        istringstream sin(log);
        string action;
        sin>>action;
        if(action=="Enter"||action=="Change"){
            string uid, nick;
            sin>>uid>>nick;
            nickname[uid] = nick;
        }
    }
    
    for(string log : record){
        istringstream sin(log);
        string action, uid;
        sin>>action>>uid;
        if(action=="Enter"){
            answer.push_back(nickname[uid]+"님이 들어왔습니다.");
        }else if(action=="Leave"){
            answer.push_back(nickname[uid]+"님이 나갔습니다.");
        }
    }
    return answer;
}