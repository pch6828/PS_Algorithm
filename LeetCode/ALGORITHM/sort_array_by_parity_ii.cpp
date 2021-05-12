class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int>answer;
        queue<int>q[2];
        
        for(auto i : nums){
            q[i%2].push(i);
        }
        
        while(!q[0].empty()){
            answer.push_back(q[0].front());
            answer.push_back(q[1].front());
            q[0].pop();
            q[1].pop();
        }
        return answer;
    }
};