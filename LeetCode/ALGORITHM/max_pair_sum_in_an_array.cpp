class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans = -1;

        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                int a = nums[i], b = nums[j];
                int a_ = 0, b_ = 0;

                while(a){
                    a_ = max(a_, a%10);
                    a/=10;
                }
                while(b){
                    b_ = max(b_, b%10);
                    b/=10;
                }

                if(a_==b_){
                    ans = max(ans, nums[i]+nums[j]);
                }
            }
        }

        return ans;
    }
};