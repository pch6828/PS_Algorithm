class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int cnt[100001] = {0};
        vector<int>ans;
        sort(changed.begin(), changed.end());
        
        for(int i : changed){
            if(cnt[i]){
                cnt[i]--;
            }else{
                if(i*2>100000){
                    return vector<int>();
                }
                cnt[i*2]++;
                ans.push_back(i);
            }
        }
        
        for(int i = 0; i <= 100000; i++){
            if(cnt[i]){
                return vector<int>();
            }
        }
        return ans;
    }
};