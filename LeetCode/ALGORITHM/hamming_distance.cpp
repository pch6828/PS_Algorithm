class Solution {
public:
    int hammingDistance(int x, int y) {
        int t = x^y;
        int answer = 0;
        
        while(t){
            answer += t%2;
            t/=2;
        }
        
        return answer;
    }
};