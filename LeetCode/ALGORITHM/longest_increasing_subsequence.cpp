class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>lis;
        
        for(int i : nums){
            if(lis.empty()||lis.back()<i){
                lis.push_back(i);
            }else{
                *lower_bound(lis.begin(), lis.end(), i) = i;
            }
        }
        
        return lis.size();
    }
};