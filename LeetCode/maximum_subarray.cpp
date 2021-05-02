class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, answer = INT_MIN;
        for(int i : nums){
            if(sum+i>i){
                sum += i;
            }else{
                sum = i;
            }
            answer = max(answer, sum);
        }
        return answer;
    }
};