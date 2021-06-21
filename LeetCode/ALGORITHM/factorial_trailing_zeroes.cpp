class Solution {
public:
    int trailingZeroes(int n) {
        int answer = 0, mul = 1;
        
        while(n){
            n/=5;
            answer += n;
        }
        
        return answer;
    }
};