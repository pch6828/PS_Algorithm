class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int answer = 0;
        
        for(auto i : nums){
            i = abs(i);
            int d = 0;
            while(i){
                d++;
                i/=10;
            }
            answer += !(d%2);
        }
        
        return answer;
    }
};