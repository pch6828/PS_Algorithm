class Solution {
public:
    int xorOperation(int n, int start) {
        int answer = 0;
        
        for(int i = 0; i < n; i++, start += 2){
            answer^=start;
        }
        
        return answer;
    }
};