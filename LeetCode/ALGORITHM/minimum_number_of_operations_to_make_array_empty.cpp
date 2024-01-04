class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int cnt[1000001] = {0,};
        int m = 0;

        for(int i : nums){
            cnt[i]++;
            m = max(m, i);
        }

        for(int i = 1; i <= m; i++){
            if(cnt[i] == 1) return -1;
            else if(cnt[i] % 3 == 0) ans += cnt[i] / 3;
            else ans += cnt[i] / 3 + 1;
        }

        return ans;
    }
};