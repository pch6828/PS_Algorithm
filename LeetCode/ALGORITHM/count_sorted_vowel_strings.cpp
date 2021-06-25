class Solution {
public:
    int countVowelStrings(int r) {
        int n = r+4;
        
        r = min(r, 4);
        
        int a = 1, b = 1;
        
        for(; r > 0; r--, n--){
            a*=n;
            b*=r;
        }
        
        return a/b;
    }
};