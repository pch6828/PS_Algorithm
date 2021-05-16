class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int>answer;
        int idx = 0;
        
        for(auto now : nums2){
            while(idx < nums1.size() && nums1[idx]<now){
                idx++;
            }
            if(idx < nums1.size() && nums1[idx]==now){
                answer.push_back(now);
                idx++;
            }
        }
        
        return answer;
    }
};