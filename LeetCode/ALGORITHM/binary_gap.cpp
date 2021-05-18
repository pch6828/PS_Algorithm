class Solution {
public:
    int binaryGap(int n) {
        int prev_idx = -1, idx = 0;
        int answer = 0;
        
        while(n){
            if(n%2){
                if(~prev_idx){
                    answer = max(answer, idx-prev_idx);
                }
                prev_idx = idx;
            }
            n/=2;
            idx++;
        }
        
        return answer;
    }
};