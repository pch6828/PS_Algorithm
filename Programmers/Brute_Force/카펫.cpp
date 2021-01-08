#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown+yellow;
    
    for(int i = 1; i <= sqrt(total); i++){
        if(total%i==0){
            int j = total/i;
            if(max(i-2,0)*max(j-2,0)==yellow){
                answer.push_back(j);
                answer.push_back(i);
                break;
            }
        }
    }
    return answer;
}