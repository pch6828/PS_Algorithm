class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        long long answer;
        if(!next_permutation(s.begin(), s.end())||(answer = stoll(s))>INT_MAX){
            return -1;
        }
        
        return answer;
    }
};