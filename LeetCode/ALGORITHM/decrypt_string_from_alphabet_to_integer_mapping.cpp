class Solution {
public:
    string freqAlphabets(string s) {
        reverse(s.begin(), s.end());
        string answer;
        int flag = 0;
        int now = 0;
        int idx = 0;
        
        while(idx < s.size()){
            if(s[idx]=='#'){
                now = (s[idx+1]-'0')+(s[idx+2]-'0')*10;
                now--;
                idx+=3;
            }else{
                now = s[idx]-'0';
                now--;
                idx++;
            }
            answer.push_back('a'+now);
        }
        reverse(answer.begin(), answer.end());
        
        return answer;
    }
};