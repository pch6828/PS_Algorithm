#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int clothes[32] = {0,};
    
    for(int i = 1; i <= n; i++){
        clothes[i] = 1;
    }
    
    for(int i : lost){
        clothes[i]--;
    }
    
    for(int i : reserve){
        clothes[i]++;
    }
    
    for(int i = 1; i <=n; i++){
        if(clothes[i]==0&&clothes[i-1]==2){
            clothes[i]++;
            clothes[i-1]--;
        }
        
        if(clothes[i]==0&&clothes[i+1]==2){
            clothes[i]++;
            clothes[i+1]--;
        }
    }
    for(int i = 1; i <= n; i++){
        answer += !!clothes[i];   
    }
    return answer;
}