class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt[3] = {0,0,0};
        for(int i : nums){
            cnt[i]++;
        }
        int idx = 0;
        for(int i = 0; i < 3; i++){
            while(cnt[i]--){
                nums[idx++] = i;
            }
        }
    }
};