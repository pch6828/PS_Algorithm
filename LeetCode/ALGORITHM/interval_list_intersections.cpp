class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>>answer;
        int l1 = firstList.size();
        int l2 = secondList.size();
        int i = 0, j = 0;
        
        while(i<l1&&j<l2){
            auto a = firstList[i];
            auto b = secondList[j];
            
            if(a[0]>b[1]){
                j++;
            }else if(a[1]<b[0]){
                i++;
            }else{
                vector<int>intersect;
                
                intersect.push_back(max(a[0], b[0]));
                intersect.push_back(min(a[1], b[1]));
                
                if(a[1]>b[1]){
                    j++;
                }else{
                    i++;
                }
                answer.push_back(intersect);
            }
        }
        return answer;
    }
};