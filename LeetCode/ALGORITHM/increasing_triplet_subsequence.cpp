class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int>lis;

        for(int i : nums){
            if(lis.empty() || lis.back() < i){
                lis.push_back(i);
            }else{
                *lower_bound(lis.begin(), lis.end(), i) = i;
            }

            if(lis.size()==3){
                return true;
            }
        }

        return false;
    }
};