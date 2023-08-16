class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>>pq;
        vector<int>ans;

        for(int i = 0; i < nums.size(); i++){
            pq.push({nums[i], i});
            
            while(pq.top().second <= i-k){
                pq.pop();
            }

            if(pq.size()>=k)
                ans.push_back(pq.top().first);
        }

        return ans;
    }
};