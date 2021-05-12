class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int chk[101] = {0,};
        int sum = 0;
        
        for(int i : nums){
            if(!chk[i]){
                sum+=i;
                chk[i] = 1;
            }else if(chk[i]==1){
                sum-=i;
                chk[i]++;
            }
        }
        
        return sum;
    }
};