class Solution {
public:
    int findComplement(int num) {
        int answer = 0;
        stack<int>bit;
        do{
            bit.push(!(num%2));
            num/=2;
        }while(num);
        while(!bit.empty()){
            answer*=2;
            answer+=bit.top();
            bit.pop();
        }
        return answer;        
    }
};