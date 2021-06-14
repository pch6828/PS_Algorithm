class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int answer = -1, distance = INT_MAX;
        
        for(int i = 0; i < points.size(); i++){
            int px = points[i][0], py = points[i][1];
            
            if((px==x||py==y)&&(abs(px-x)+abs(py-y)) < distance){
                distance = (abs(px-x)+abs(py-y));
                answer = i;
            }
        }
        
        return answer;
    }
};