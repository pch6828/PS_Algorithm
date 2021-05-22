class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int answer = 0, remainder = 0;
        
        while(numBottles){
            answer+=numBottles;
            remainder += numBottles;
            numBottles = remainder / numExchange;
            remainder %= numExchange;
        }
        
        return answer;
    }
};