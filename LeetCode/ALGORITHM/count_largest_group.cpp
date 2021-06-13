class Solution {
public:
    int countLargestGroup(int n) {
        map<int, int>cnt;
        int answer = 0, maximum = 0;
        
        for(int i = 1; i <= n; i++){
            int t = i;
            int sum = 0;
            while(t){
                sum+=t%10;
                t/=10;
            }
            cnt[sum]++;
        }
        
        for(auto p : cnt){
            if(maximum < p.second){
                maximum = p.second;
                answer = 1;
            }else if(maximum == p.second){
                answer++;
            }
        }
        
        return answer;
    }
};