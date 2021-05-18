class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream sin(sentence);
        int idx = 0;
        string word;
        
        while(sin>>word){
            idx++;
            if(word.size() < searchWord.size()){
                continue;
            }
            
            if(word.substr(0, searchWord.size())==searchWord){
                return idx;
            }
        }
        
        return -1;
    }
};