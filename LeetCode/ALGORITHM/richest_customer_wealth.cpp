class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int answer = 0;
        for(auto& v : accounts){
            int sum = 0;
            for(int i : v){
                sum+=i;
            }
            answer = max(answer, sum);
        }
        return answer;
    }
};