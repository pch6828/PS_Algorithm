class Solution {
public:
    int maxArea(vector<int>& height) {
        deque<pair<int, int>>s;
        int ans = 0;

        for(int i = 0; i < height.size(); i++){
            int h = height[i];

            for(auto& p : s){
                ans = max(ans, (i - p.second)*min(p.first, h));
            }

            if(s.empty() || s.back().first < h)
                s.push_back({h, i});
        }

        return ans;
    }
};