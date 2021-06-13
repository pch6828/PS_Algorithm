class Solution {
public:
    bool cntchar(string& s, int k){
        char c = s.back();
        if(s.size() < k){
            return false;
        }
        for(int i = s.size()-1, cnt = 0; i >= 0&&cnt < k; i--, cnt++){
            if(c!=s[i]){
                return false;
            }
        }
        return true;
    }
    
    string removeDuplicates(string s, int k) {
        string answer;
        
        for(auto c : s){
            if(answer.empty()||answer.back()!=c||!cntchar(answer, k-1)){
                answer.push_back(c);
            }else{
                int t = k-1;
                while(t--){
                    answer.pop_back();
                }
            }
        }
        
        return answer;
    }
};