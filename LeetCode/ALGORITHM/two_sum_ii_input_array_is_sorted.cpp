class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans;

        for(int i = 0; i < numbers.size(); i++){
            int t = numbers[i];

            auto it = lower_bound(numbers.begin()+i+1, numbers.end(), target - t);
            if(it != numbers.end() && *it == target - t){
                ans.push_back(i + 1);
                ans.push_back(it - numbers.begin() + 1);
                break;
            }
        }

        return ans;
    }
};