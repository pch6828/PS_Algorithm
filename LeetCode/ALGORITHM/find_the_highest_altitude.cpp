class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int answer = 0;
        int sum = 0;
        
        for(int i : gain){
            sum += i;
            answer = max(sum, answer);
        }
        
        return answer;
    }
};