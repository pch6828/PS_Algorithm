#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

class compare{
public:
    bool operator()(pair<int, int>&a, pair<int, int>&b){
        if(a.second == b.second){
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    int cnt = 0;
    int average = 0;
    int n = jobs.size();
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>job;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare>waiting; 
    for(auto p : jobs){
        job.push({p[0], p[1]});
    }
    
    waiting.push(job.top());
    job.pop();
    
    while(!waiting.empty()){
        pair<int, int>now = waiting.top();
        waiting.pop();
        
        cnt = max(cnt, now.first)+now.second;
        average += cnt-now.first;
        while(!job.empty()){
            pair<int, int>next = job.top();
            if(next.first <= cnt){
                job.pop();
                waiting.push(next);
            }else{
                break;
            }
        }
        if(waiting.empty() && !job.empty()){
            pair<int, int>next = job.top();
            job.pop();
            waiting.push(next);
        }
    }
    
    return average / n;
}