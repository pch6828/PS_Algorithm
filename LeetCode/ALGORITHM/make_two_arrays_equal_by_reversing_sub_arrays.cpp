class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        int idx = 0;
        
        for(int i : arr){
            bool flag = false;
            while(idx < target.size()&&i>=target[idx]){
                if(i==target[idx]){
                    flag = true;
                }
                idx++;
                if(flag){
                    break;
                }
            }
            if(!flag){
                return false;
            }
        }
        return true;
    }
};