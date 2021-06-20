class Solution {
public:
    string convertToBase7(int num) {
        string answer;
        bool sign = num < 0;
        
        num = abs(num);
        
        do{
            answer.push_back(num%7+'0');
            num/=7;
        }while(num);
        
        if(sign){
            answer.push_back('-');
        }
        
        reverse(answer.begin(), answer.end());
        
        return answer;
    }
};