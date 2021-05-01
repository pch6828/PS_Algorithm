class Solution {
public:
    int myAtoi(string s) {
        long long sign = 1, answer = 0;
        
        int i = 0;
        while(i < s.size() && s[i]==' '){
            i++;
        }
        
        if(s[i]=='-'){
            sign = -1;
            i++;
        }else if(s[i]=='+'){
            i++;
        }
        
        while(i<s.size() && '0' <= s[i] && s[i] <= '9'){
            answer*=10;
            answer+=s[i]-'0';
            
            if(sign==1&&answer>=INT_MAX){
                return INT_MAX;
            }else if(sign==-1&&-answer<=INT_MIN){
                return INT_MIN;
            }
            i++;
        }
        
        return answer*sign;
    }
};