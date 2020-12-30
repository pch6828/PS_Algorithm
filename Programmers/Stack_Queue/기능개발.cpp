#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> days;
    for(int i = 0; i < progresses.size(); i++){
        int day = (100-progresses[i])/speeds[i]+!!((100-progresses[i])%speeds[i]);
        days.push(day);
    }
    stack<int>longest_work;
    while(!days.empty()){
        int now = days.front();
        days.pop();
        
        if(longest_work.empty()||longest_work.top()<now){
            longest_work.push(now);
            answer.push_back(1);
        }else{
            answer.back()++;
        }
    }
    return answer;
}