class Solution {
private:
    static const int MOD = 1000000007;
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        long long dp[1000] = {0, };
        long long ans = 0;
        
        for(int i = 0; i < arr.size(); i++){
            int l = 0, r = i;
            long long lv, rv, iv = arr[i];
            while(l<=r){
                lv = arr[l];
                rv = arr[r];
                if(lv*rv<iv){
                    l++;
                }else if(lv*rv>iv){
                    r--;         
                }else{
                    dp[i]+=dp[l]*dp[r];
                    dp[i]%=MOD;
                    if(l!=r){
                        dp[i]+=dp[l]*dp[r];
                        dp[i]%=MOD;
                    }
                    l++;
                    r--;
                }
            }
            dp[i]++;
            dp[i]%=MOD;
            ans += dp[i];
            ans %= MOD;
        }
        return ans;
    }
};