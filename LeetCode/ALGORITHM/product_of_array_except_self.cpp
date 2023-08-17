class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        deque<int>prefix, postfix;
        vector<int>ans;

        prefix.push_back(1);
        postfix.push_back(1);

        for(int i = 0; i < nums.size() - 1; i++){
            prefix.push_back(prefix.back()*nums[i]);
            postfix.push_front(postfix.front()*nums[nums.size()-1-i]);
        }

        for(int i = 0; i < nums.size(); i++){
            ans.push_back(postfix[i]*prefix[i]);
        }

        return ans;
    }
};