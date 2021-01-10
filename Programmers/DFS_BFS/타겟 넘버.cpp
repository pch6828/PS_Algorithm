#include <string>
#include <vector>

using namespace std;

int answer = 0;

void dfs(vector<int>& numbers, int now, int idx){
    if(idx==numbers.size()){
        if(now==0){
            answer++;
        }
        return;
    }
    dfs(numbers, now+numbers[idx], idx+1);
    dfs(numbers, now-numbers[idx], idx+1);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0);
    
    return answer;
}