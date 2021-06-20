class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int answer = 1, length = 1, prev = nums[0];

        for(int i = 1; i < nums.size(); i++){
            if(prev < nums[i]){
                length++;
            }else{
                length = 1;
            }
            prev = nums[i];
            answer = max(answer, length);
        }
        
        return answer;
    }
};