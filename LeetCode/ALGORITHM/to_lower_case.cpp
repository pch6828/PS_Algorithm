class Solution {
public:
    string toLowerCase(string str) {
        for(auto& c : str){
            if('A'<=c&&c<='Z'){
                c += 32;
            }
        }
        return str;
    }
};