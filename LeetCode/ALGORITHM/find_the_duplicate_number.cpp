class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow1, slow2, fast;
        slow1 = slow2 = fast = nums[0];

        do{
            slow1 = nums[slow1];
            fast = nums[nums[fast]];
        }while(slow1 != fast);

        while(slow1 != slow2){
            slow1 = nums[slow1];
            slow2 = nums[slow2];
        }

        return slow2;
    }
};