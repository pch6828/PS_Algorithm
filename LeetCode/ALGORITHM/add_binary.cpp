class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int i = 0, carry = 0;
        string answer;
        int la = a.size(), lb = b.size();
        while(i<la||i<lb||carry){
            int a_bit = i<la?a[i]-'0':0;
            int b_bit = i<lb?b[i]-'0':0;
            
            i++;
            
            int sum_bit = a_bit+b_bit+carry;
            
            carry = sum_bit/2;
            answer.push_back(sum_bit%2+'0');
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};