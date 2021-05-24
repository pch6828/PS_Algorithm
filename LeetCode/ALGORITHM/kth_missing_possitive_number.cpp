class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int idx = 0, target = 1;
        
        while(idx < arr.size()){
            if(arr[idx]==target){
                idx++;
            }else{
                k--;
            }
            
            if(!k){
                return target;
            }
            target++;
        }
        
        return arr.back()+k;
    }
};