#define MOD 1337

class Solution {
public:
    int myPow(int a, int b){
        if(!b){
            return 1;
        }
        int sqr = myPow(a, b/2);
        return ((b%2?a:1)*((sqr*sqr)%MOD)) % MOD;
    }
    
    int superPow(int a, vector<int>& b) {
        a %= MOD;
        
        reverse(b.begin(), b.end());
        
        int result = 1;
        
        for(auto i : b){
            result *= myPow(a, i);
            result %= MOD;
            
            a = myPow(a, 10);
        }
        return result;
    }
};