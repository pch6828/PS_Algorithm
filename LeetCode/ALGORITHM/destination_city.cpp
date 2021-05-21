class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string>A, B;
        
        for(auto& v : paths){
            A.insert(v[0]);
            B.erase(v[0]);
            if(!A.count(v[1])){
                B.insert(v[1]);
            }
        }
        
        return *B.begin();
    }
};