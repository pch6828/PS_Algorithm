class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        vector<int>answer;
        
        for(int i : nums){
            if(abs(i)%2==0){
                sum+=i;
            }
        }
        
        for(auto& q : queries){
            if(abs(nums[q[1]])%2==0){
                sum-=nums[q[1]];
            }
            nums[q[1]] += q[0];
            if(abs(nums[q[1]])%2==0){
                sum+=nums[q[1]];
            }
            answer.push_back(sum);
        }
        
        return answer;
    }
};