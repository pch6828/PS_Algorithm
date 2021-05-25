class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>answer;
        
        for(int i = 0; i <= n; i++){
            int t = i;
            int cnt = 0;
            while(t){
                cnt+=t%2;
                t/=2;
            }
            answer.push_back(cnt);
        }
        
        return answer;
    }
};