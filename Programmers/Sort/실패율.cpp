#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<double> cnt1, cnt2;

bool compare(int a, int b){
    double va = (cnt2[a]!=0?(cnt2[a]-cnt1[a])/cnt2[a]:0);
    double vb = (cnt2[b]!=0?(cnt2[b]-cnt1[b])/cnt2[b]:0);
    if(va==vb){
        return a < b;
    }
    return va > vb;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    cnt1.resize(N+1);
    cnt2.resize(N+1);
    
    for(int now : stages){
        for(int i = 1; i < now; i++){
            cnt1[i]+=1;
            cnt2[i]+=1;
        }
        if(now<=N){
            cnt2[now]+=1;
        }
    }
    for(int i = 1; i <= N; i++){
        answer.push_back(i);
    }
    sort(answer.begin(), answer.end(), compare);
    
    return answer;
}