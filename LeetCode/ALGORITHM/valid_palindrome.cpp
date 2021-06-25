class Solution {
public:
    bool isPalindrome(string s) {
        stack<char>a;
        queue<char>b;
        
        for(char c : s){
            if('0'<=c&&c<='9'){
                a.push(c);
                b.push(c);
            }else if('a'<=(c|32)&&(c|32)<='z'){
                a.push(c|32);
                b.push(c|32);
            }
        }
        
        while(!a.empty()){
            if(a.top()!=b.front()){
                return false;
            }
            a.pop();
            b.pop();
        }
        
        return true;
    }
};