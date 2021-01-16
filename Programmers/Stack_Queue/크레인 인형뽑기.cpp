#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int>bucket;
    for(auto m : moves){
        int idx = m-1;
        for(auto& row : board){
            if(row[idx]){
                if(!bucket.empty()&&bucket.top()==row[idx]){
                    bucket.pop();
                    answer++;
                    answer++;
                }else{
                    bucket.push(row[idx]);
                }
                row[idx] = 0;
                break;
            }
        }
    }
    
    return answer;
}