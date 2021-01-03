#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>>pq;
    for(auto i : scoville){
        pq.push(i);
    }
    
    while(pq.size() != 1 && pq.top() < K){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a + b * 2);
        answer++;
    }
    if(pq.top() < K){
        answer = -1;
    }
    return answer;
}