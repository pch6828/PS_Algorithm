class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        string str2 = str;
        
        reverse(str2.begin(), str2.end());
        
        return str==str2;
    }
};