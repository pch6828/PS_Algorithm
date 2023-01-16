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

// second solution
class Solution2 {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        bool inserted = false;

        for(auto& interval : intervals){
            if(!inserted){
                if(newInterval[0]<interval[0]){
                    if(newInterval[1]<interval[0]){
                        ans.push_back(newInterval);
                        ans.push_back(interval);
                    }else{
                        newInterval[1] = max(newInterval[1], interval[1]);
                        ans.push_back(newInterval);
                    }
                    inserted = true;
                }else{
                    if(newInterval[0]>interval[1]){
                        ans.push_back(interval);
                    }else{
                        interval[1] = max(interval[1], newInterval[1]);
                        ans.push_back(interval);
                        inserted = true;
                    }
                }
            }else{
                auto& prevInterval = ans.back();
                if(prevInterval[1]>=interval[0]){
                    prevInterval[1] = max(prevInterval[1], interval[1]);
                }else{
                    ans.push_back(interval);
                }
            }
        }

        if(!inserted){
            ans.push_back(newInterval);
        }

        return ans;
    }
};