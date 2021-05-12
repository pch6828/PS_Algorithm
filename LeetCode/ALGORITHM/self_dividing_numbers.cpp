class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>answer;
        for(int i = left; i <= right; i++){
            int t = i;
            bool flag = true;
            
            while(t){
                if(t%10){
                    int r = t%10;
                    if(i%r){
                        flag = false;
                        break;
                    }
                }else{
                    flag = false;
                    break;
                }
                t/=10;
            }
            
            if(flag){
                answer.push_back(i);
            }
        }
        return answer;
    }
};