class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long>s;
        
        s.insert(1);
        
        while(n--){
            long long now;
            
            now = *s.begin();
            s.erase(s.begin());
            
            if(n){
                s.insert(now*2);
                s.insert(now*3);
                s.insert(now*5);
            }else{
                return now;
            }
        }
        return 0;
    }
};