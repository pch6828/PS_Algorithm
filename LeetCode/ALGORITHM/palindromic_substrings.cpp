class Solution {
public:
    int countSubstrings(string s) {
        int answer = 0, n = s.size();
        
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= n-i; j++){
                string a, b;
                a = b = s.substr(j, i);
                reverse(a.begin(), a.end());
                
                answer+=a==b;
            }
        }
        
        return answer;
    }
};