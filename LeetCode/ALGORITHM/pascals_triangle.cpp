class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back(vector<int>({1}));
        
        for(int i = 2; i <= numRows; i++){
            vector<int>row;
            row.push_back(1);
            for(int j = 1; j < ans.back().size(); j++){
                row.push_back(ans.back()[j]+ans.back()[j-1]);
            }
            row.push_back(1);
            
            ans.push_back(row);
        }
        
        return ans;
    }
};