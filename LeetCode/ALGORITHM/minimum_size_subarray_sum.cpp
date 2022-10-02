class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, sum = nums[0], ans = INT_MAX;
        
        while(l < nums.size()){
            if(sum>=target){
                ans = min(ans, r-l+1);
                if(l<nums.size()){
                    sum -= nums[l];   
                }
                l++;
                if(l>r){
                    r++;
                    if(r<nums.size()){
                        sum += nums[r];
                    }
                }
            }else{
                r++;
                if(r<nums.size()){
                    sum += nums[r];
                }else{
                    break;
                }
            }
        }
        
        return ans == INT_MAX ? 0 : ans;
    }
};