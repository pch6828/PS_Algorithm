class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int greatest = *max_element(candies.begin(), candies.end());
        vector<bool>answer;
        for(int i : candies){
            answer.push_back(greatest - i <= extraCandies);
        }
        return answer;
    }
};