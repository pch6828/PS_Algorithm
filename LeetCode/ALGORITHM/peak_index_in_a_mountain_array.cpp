class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int a, b, c, d;
        int ans;
        int maximum = INT_MIN;
        a = 0, d = arr.size() - 1;

        while(d - a > 2){
            b = (a*2+d)/3;
            c = (a+d*2)/3;

            if(arr[b] <= arr[c])
                a = b;
            else
                d = c;
        }

        for(int i = a; i <= d; i++){
            if(maximum < arr[i]){
                maximum = arr[i];
                ans = i;
            }
        }

        return ans;
    }
};