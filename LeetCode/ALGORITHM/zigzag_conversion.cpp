class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }
        
        string answer;
        vector<string>arr(numRows);
        int idx = 0, direction = 1;
        
        for(char c : s){
            arr[idx].push_back(c);
            if(idx+direction==-1){
                direction = 1;
            }else if(idx+direction==numRows){
                direction = -1;
            }
            idx+=direction;
        }
        
        for(auto& s : arr){
            answer += s;
        }
        
        return answer;
    }
};