class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return vector<string>();
        }
        string arr[10] = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        
        vector<string>answer[2];
        int n = digits.size();
        for(char c : arr[digits[0]-'0']){
            answer[0].push_back(string(1, c));
        }
        for(int i = 1; i < n; i++){
            answer[i%2].clear();
            for(auto& s : answer[(i-1)%2]){
                for(char c : arr[digits[i]-'0']){
                    answer[i%2].push_back(s);
                    answer[i%2].back().push_back(c);
                }
            }
        }
        
        return answer[(n-1)%2];
    }
};