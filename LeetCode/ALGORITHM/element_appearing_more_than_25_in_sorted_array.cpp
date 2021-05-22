class Solution {
public:
    int findSpecialInteger(vector<int>& nums) {
        int answer = nums[0], answer_cnt = 1, cnt = 1, prev = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            if(prev==nums[i]){
                cnt++;
            }else{
                cnt = 1;
            }
            if(answer_cnt <= cnt){
                answer_cnt = cnt;
                answer = nums[i];
            }
            prev = nums[i];
        }
        
        return answer;
    }
};