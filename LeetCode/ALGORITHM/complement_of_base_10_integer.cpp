class Solution {
public:
    int bitwiseComplement(int N) {
        int answer = 0;
        stack<int>bit;
        do{
            bit.push(!(N%2));
            N/=2;
        }while(N);
        while(!bit.empty()){
            answer*=2;
            answer+=bit.top();
            bit.pop();
        }
        return answer;
    }
};