class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l, r;

        l = 1;
        r = 0;
        
        for(int i : batteries){
            r += i;
        }
        r/=n;

        while(l < r){
            long long mid = (l+r+1)/2;
            long long t = 0;

            for(int i : batteries){
                t += min(mid, (long long)i);
            }

            if(t >= mid*n){
                l = mid;
            }else{
                r = mid - 1;
            }
        }

        return l;
    }
};