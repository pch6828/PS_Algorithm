class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int, int>cnt;
        vector<int>answer;
        
        for(int i : nums){
            cnt[i]++;
        }
        
        for(auto p : cnt){
            if(p.second==1){
                answer.push_back(p.first);
            }
        }
        return answer;      
    }
};