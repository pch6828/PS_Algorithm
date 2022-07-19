class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans;
        ans.push_back(1);
        
        for(int i = 1; i <= rowIndex; i++){
            ans.push_back(1);
            for(int j = ans.size()-2; j >= 1; j--){
                ans[j]+=ans[j-1];
            }
        }
        
        return ans;
    }
};