#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    citations.push_back(0);
    for(int i = 0; i < citations.size(); i++){
        if(citations[i]<=i){
            answer = i;
            break;
        }
    }
    return answer;
}