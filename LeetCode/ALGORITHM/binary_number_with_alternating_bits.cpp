class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev_bit = -1;
        
        while(n){
            int bit = n%2;
            n/=2;
            if(!(prev_bit^bit)){
                return false;
            }
            prev_bit = bit;
        }
        
        return true;
    }
};