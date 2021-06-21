class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>answer;
        
        int now = 1;
        
        for(int i : target){
            while(i!=now){
                answer.push_back("Push");
                answer.push_back("Pop");
                now++;
            }
            answer.push_back("Push");
            now++;
        }
        
        return answer;
    }
};