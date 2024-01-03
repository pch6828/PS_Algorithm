class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;
        int ans = 0;
        for(auto& s : bank){
            int cnt = 0;
            for(char c : s){
                cnt += (c == '1');
            }
            if(cnt){
                ans += prev * cnt;
                prev = cnt;
            }
        }
        return ans;
    }
};