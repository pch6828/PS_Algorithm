class Solution {
public:
    static bool cmp(const vector<int>&a, const vector<int>&b){
        if(a[0]==b[0]){
            return a[1]<b[1];
        }
        return a[0]<b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>answer;
        sort(intervals.begin(), intervals.end(), cmp);
        
        answer.push_back(intervals[0]);
        
        for(int i = 1; i < intervals.size(); i++){
            auto& a = answer.back();
            auto& b = intervals[i];
            
            if(a[1]<b[0]){
                answer.push_back(b);
            }else{
                a[1] = max(a[1], b[1]);
            }
        }
        
        return answer;
    }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};