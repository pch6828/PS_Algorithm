#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int cnt[201] = {0,};
    for(int i = 0; i < numbers.size(); i++){
        for(int j = i+1; j < numbers.size(); j++){
            cnt[numbers[i]+numbers[j]]++;
        }
    }
    for(int i = 0; i <=200; i++){
        if(cnt[i]){
            answer.push_back(i);
        }
    }
    return answer;
}