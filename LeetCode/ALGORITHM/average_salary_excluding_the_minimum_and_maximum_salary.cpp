class Solution {
public:
    double average(vector<int>& salary) {
        double sum = 0, cnt = -2;
        int minimum = INT_MAX, maximum = INT_MIN;
        
        for(int i : salary){
            minimum = min(minimum, i);
            maximum = max(maximum, i);
            
            sum+=i;
            cnt+=1;
        }
        
        sum -= minimum;
        sum -= maximum;
        
        return sum/cnt;
    }
};