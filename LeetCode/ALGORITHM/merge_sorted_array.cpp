class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, idx = n+m-1;
        
        while(i>=0||j>=0){
            int a = i>=0?nums1[i]:INT_MIN;
            int b = j>=0?nums2[j]:INT_MIN;
            
            if(a>b){
                nums1[idx] = a;
                i--;
            }else{
                nums1[idx] = b;
                j--;
            }
            idx--;
        }
    }
};