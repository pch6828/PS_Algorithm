class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0){
            return 0;
        }
        int n = haystack.size(), m = needle.size();
        for(int i = 0; i < n - m + 1; i++){
            if(haystack[i]==needle[0]){
                bool flag = true;
                for(int j = 1; j < m; j++){
                    if(haystack[i+j]!=needle[j]){
                        flag = false;
                        break;
                    }
                }
                
                if(flag){
                    return i;
                }
            }
        }
        
        return -1;
    }
};