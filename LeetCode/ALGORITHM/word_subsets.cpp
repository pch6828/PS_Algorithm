class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int cnt[26] = {0,};
        vector<string>ans;
        for(auto& word2 : words2){
            int temp[26] = {0,};     
            for(char c: word2){
                temp[c-'a']++;
            }
            for(int i = 0; i < 26; i++){
                cnt[i] = max(cnt[i], temp[i]);
            }
       }
        
        for(auto& word1 : words1){
            bool flag = true;
            int temp[26] = {0,};       
            for(char c: word1){
                temp[c-'a']++;
            }
            for(int i = 0; i < 26; i++){
                if(cnt[i]>temp[i]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans.push_back(word1);
            }
        }
        return ans;
    }
};