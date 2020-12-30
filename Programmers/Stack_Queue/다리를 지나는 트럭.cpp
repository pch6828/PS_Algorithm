#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, total = 0, i = 0;
    queue<pair<int, int>>bridge;
    while (true) {
        if (i == truck_weights.size() && bridge.empty()) {
            break;
        }
        if (!bridge.empty() && answer - bridge.front().first >= bridge_length) {
            total -= truck_weights[bridge.front().second];
            bridge.pop();
        }
        if (i != truck_weights.size()&&total + truck_weights[i] <= weight) {
            bridge.push({ answer, i });
            total += truck_weights[i];
            i++;
        }
        else if(!bridge.empty()){
            answer = bridge.front().first + bridge_length;
            continue;
        }
        answer++;
    }
    return answer;
}