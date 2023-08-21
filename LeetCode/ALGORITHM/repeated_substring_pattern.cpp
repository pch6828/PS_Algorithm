class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ss = s+s;
        string check = ss.substr(1, ss.size()-2);

        return check.find(s)!=-1;
    }
};