class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>answer;
        
        for(int i = 0; i < nums.size(); i++){
            int t = -1;
            for(int j = i, cnt = 0; cnt < nums.size(); j=(j+1)%nums.size(), cnt++){
                if(nums[i]<nums[j]){
                    t = nums[j];
                    break;
                }
            }
            answer.push_back(t);
        }
        
        return answer;
    }
};