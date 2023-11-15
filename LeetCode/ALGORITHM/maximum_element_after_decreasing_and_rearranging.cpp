class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int ans = 1;
        sort(arr.begin(), arr.end());
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] > arr[i-1]+1)
                arr[i] = arr[i-1]+1;
            ans = min(i+1, arr[i]);
        }
        return ans;
    }
};