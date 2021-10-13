class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>s;
        
        for(int i : nums){
            s.insert(i);
        }
        
        int target = 1;
        
        while(true){
            if(s.count(target)==0){
                return target;
            }
            target++;
        }
        
        return -1;
    }
};