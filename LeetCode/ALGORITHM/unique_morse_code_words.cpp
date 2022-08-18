class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>code;
        string arr[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for(string& word : words){
            string t;
            for(char c : word){
                t+=arr[c-'a'];
            }
            code.push_back(t);
        }
        
        sort(code.begin(), code.end());
        auto it = unique(code.begin(), code.end());
        return it-code.begin();
    }
};