class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int>m1, m2;
        for(int i : arr){
            m1[i]++;
        }
        for(auto i : m1){
            m2[i.second]++;
        }
        for(auto i : m2){
            if(i.second>1){
                return false;
            }
        }
        return true;
    }
};