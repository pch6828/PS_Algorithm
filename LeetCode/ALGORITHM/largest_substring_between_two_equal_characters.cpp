class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int min_idx[26], max_idx[26], answer = -1, len = s.size();
        
        memset(min_idx, -1, sizeof(min_idx));
        memset(max_idx, -1, sizeof(max_idx));
        
        for(int i = 0; i < len; i++){
            if(min_idx[s[i]-'a']==-1||min_idx[s[i]-'a']>i){
                min_idx[s[i]-'a'] = i;
            }
            if(max_idx[s[i]-'a']==-1||max_idx[s[i]-'a']<i){
                max_idx[s[i]-'a'] = i;
            }
            
            answer = max(answer, max_idx[s[i]-'a']-min_idx[s[i]-'a']-1);
        }
        
        return answer;
    }
};