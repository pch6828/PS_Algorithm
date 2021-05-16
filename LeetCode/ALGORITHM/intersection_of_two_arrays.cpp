class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1(nums1.begin(), nums1.end());
        set<int>s2(nums2.begin(), nums2.end());
        vector<int>answer;
        
        for(int i : s1){
            if(s2.count(i)){
                answer.push_back(i);
            }
        }
        
        return answer;
    }
};