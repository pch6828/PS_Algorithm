#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    int pick[3][10] = {{1,2,3,4,5},
                     {2,1,2,3,2,4,2,5},
                     {3,3,1,1,2,2,4,4,5,5}};
    int size[3] = {5,8,10};
    int AC[3] = {0,0,0};
    vector<int> answer;
    
    for(int i = 0; i < answers.size(); i++){
        int ans = answers[i];
        for(int j = 0; j < 3; j++){
            if(ans==pick[j][i%size[j]]){
                AC[j]++;
            }
        }
    }
    int maximum = max(AC[0], max(AC[1], AC[2]));
    for(int i = 0; i < 3; i++){
        if(AC[i]==maximum){
            answer.push_back(i+1);
        }
    }
    return answer;
}