class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        string answer;
        
        int i = 0, carry = 0, l1 = num1.size(), l2 = num2.size();
        
        while(carry||i<l1||i<l2){
            int a = i<l1?num1[i]-'0':0;
            int b = i<l2?num2[i]-'0':0;
            int sum = a+b+carry;
            answer.push_back(sum%10+'0');
            carry = sum/10;
            i++;
        }
            
        reverse(answer.begin(), answer.end());
       
        return answer;
    }
};