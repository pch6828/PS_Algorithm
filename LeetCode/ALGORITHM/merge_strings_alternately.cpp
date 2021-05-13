class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string answer;
        int idx = 0, len1 = word1.size(), len2 = word2.size();
        
        while(idx < len1 || idx < len2){
            if(idx < len1){
                answer.push_back(word1[idx]);
            }
            if(idx < len2){
                answer.push_back(word2[idx]);
            }
            idx++;
        }
        
        return answer;
    }
};