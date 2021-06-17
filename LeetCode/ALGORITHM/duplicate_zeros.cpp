class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int>temp(arr.begin(), arr.end());
        
        arr.clear();
        for(int i : temp){
            if(!i){
                arr.push_back(i);
            }
            arr.push_back(i);
        }
        
        while(arr.size()!=temp.size()){
            arr.pop_back();
        }
    }
};