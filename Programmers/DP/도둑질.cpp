#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    if(money.size()==3){
        return *max_element(money.begin(), money.end());
    }
    int dp1[1000001] = {0,};
    int dp2[1000001] = {0,};
    int dp3[1000001] = {0,};
    dp1[0] = money[0];
    dp1[2] = money[0]+money[2];
    dp2[1] = money[1];
    dp3[2] = money[2];
    answer = max(dp1[2], max(dp2[1], dp3[2]));
    for(int i = 3; i < money.size()-1; i++){
        dp1[i] = money[i]+max(dp1[i-2], dp1[i-3]);
        answer = max(answer, dp1[i]);
    }
    for(int i = 3; i < money.size(); i++){
        dp2[i] = money[i]+max(dp2[i-2], dp2[i-3]);
        dp3[i] = money[i]+max(dp3[i-2], dp3[i-3]);  
        answer = max(answer, max(dp2[i], dp3[i]));
    }
    return answer;
}