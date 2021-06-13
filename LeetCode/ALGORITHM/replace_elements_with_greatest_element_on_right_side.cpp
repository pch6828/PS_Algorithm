class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int>answer;
        
        int maximum = -1;
        for(int i = arr.size()-1; i >= 0; i--){
            answer.push_back(maximum);
            maximum = max(maximum, arr[i]);
        }
        
        reverse(answer.begin(), answer.end());
        
        return answer;
    }
};