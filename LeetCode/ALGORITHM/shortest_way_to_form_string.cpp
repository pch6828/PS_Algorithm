class Solution {
public:
    int shortestWay(string source, string target) {
        int idx = 0;
        int len1 = target.size(), len2 = source.size();
        int answer = 1;
        
        for(int i = 0; i < len1; i++){
            bool flag = false;
            
            if(idx==len2){
                answer++;
                idx = 0;
            }
            for(int j = idx; j < len2; j++){
                if(source[j]==target[i]){
                    idx = j + 1;
                    flag = true;
                    break;
                }
            }
            
            if(!flag){
                answer++;
            }else{
                continue;
            }
            
            for(int j = 0; j < len2; j++){
                if(source[j]==target[i]){
                    idx = j + 1;
                    flag = true;
                    break;
                }
            }
            
            if(!flag){
                return -1;
            }
        }
        
        return answer;
    }
};