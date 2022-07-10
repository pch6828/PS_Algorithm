/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* partitionAndBuildBST(vector<int>&nums, int l, int r){
        if(l>r){
            return nullptr;
        }
        int mid = (l+r)/2;
        return new TreeNode(nums[mid], partitionAndBuildBST(nums, l, mid-1), partitionAndBuildBST(nums, mid+1, r));
    }    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return partitionAndBuildBST(nums, 0, nums.size()-1);
    }
};