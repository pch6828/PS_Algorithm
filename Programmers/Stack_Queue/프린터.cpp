#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int>pq;
    queue<int>loc;
    
    for(int i = 0; i < priorities.size();i++){
        loc.push(i);
        pq.push(priorities[i]);
    }
    
    while(true){
        if(pq.top()==priorities[loc.front()]){
            answer++;
            if(loc.front()==location){
                return answer;
            }
            pq.pop();
            loc.pop();
        }else{
            loc.push(loc.front());
            loc.pop();
        }
    }
}