class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>answer;
        
        for(int i : nums1){
            bool flag = false;
            int t = -1;
            for(int j : nums2){
                if(i==j){
                    flag = true;
                }
                if(flag && j > i){
                    t = j;
                    break;
                }
            }
            answer.push_back(t);
        }
        
        return answer;
    }
};