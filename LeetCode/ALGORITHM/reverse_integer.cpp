class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        if(x<0){
            ::reverse(s.begin()+1, s.end());
        }else{
            ::reverse(s.begin(), s.end());
        }
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
                return 0;
            }else if(sign==-1&&-answer<=INT_MIN){
                return 0;
            }
            i++;
        }
        
        return answer*sign;
    }
};