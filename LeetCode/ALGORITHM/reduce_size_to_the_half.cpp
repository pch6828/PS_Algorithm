class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int, int>cnt;
        vector<int>cnt_arr;
        for(int i : arr){
            cnt[i]++;
        }
        
        for(auto p : cnt){
            cnt_arr.push_back(p.second);
        }
        
        sort(cnt_arr.begin(), cnt_arr.end(), greater<int>());
        
        int sum = 0;
        int ans = 0;
        for(int i : cnt_arr){
            sum+=i;
            ans++;
            if(sum*2>=arr.size()){
                break;
            }
        }
        return ans;
    }
};