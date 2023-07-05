class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int>prefix, postfix;
        int ans = 0;

        prefix.resize(nums.size());
        postfix.resize(nums.size());

        for(int i = 0; i < nums.size(); i++){
            if(nums[i]){
                if(i){
                    prefix[i] = prefix[i-1]+1;
                }else{
                    prefix[i] = 1;
                }
            }else
                prefix[i] = 0;
        }


        for(int i = nums.size()-1; i >= 0; i--){
            if(nums[i]){
                if(i == nums.size()-1){
                    postfix[i] = 1;
                }else{
                    postfix[i] = postfix[i+1]+1;
                }
            }else
                postfix[i] = 0;
        }

        for(int i = 0; i < nums.size(); i++){
            int pre = 0, post = 0;
            if(i!=0){
                pre = prefix[i-1];
            }
            if(i!=nums.size()-1){
                post = postfix[i+1];
            }
            ans = max(ans, pre+post);
        }

        return ans;
    }
};