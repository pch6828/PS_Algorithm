#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    reverse(prices.begin(), prices.end());
    int ans;
    stack<pair<int, int>>st;
    for (int i = 0; i < prices.size(); i++){
        int now = prices[i];
        ans = i;
        
        while(!st.empty()){
            int prev = st.top().first;
            int idx = st.top().second;

            if(prev<now){
                ans -= idx;
                break;
            }
            st.pop();
        }
        st.push({now, i});
        answer.push_back(ans);
    }
    reverse(answer.begin(), answer.end());
    return answer;
}