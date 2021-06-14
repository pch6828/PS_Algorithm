class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int>cnt;
        
        for(int i : nums){
            cnt[i]++;
        }
        
        for(auto p : cnt){
            if(p.second==1){
                return p.first;
            }
        }
        return 0;
    }
};