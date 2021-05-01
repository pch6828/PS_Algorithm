class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>result;
        int cnt = 1;
        for(int i : nums){
            if(result.empty()){
                result.push_back(i);
                cnt = 1;
            }else if(cnt==1&&result.back()==i){
                result.push_back(i);
                cnt++;
            }else if(result.back()!=i){
                result.push_back(i);
                cnt = 1;
            }
        }
        nums = result;
        return nums.size();
    }
};