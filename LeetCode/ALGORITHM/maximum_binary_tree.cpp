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
public:
    TreeNode* buildTree(vector<int>& nums, int st, int en){
        if(st>en){
            return nullptr;
        }
        int idx = st;
        for(int i = st; i <= en; i++){
            if(nums[idx]<=nums[i]){
                idx = i;
            }
        }
        return new TreeNode(nums[idx], 
                            buildTree(nums, st, idx-1), 
                            buildTree(nums, idx+1, en));
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums, 0, nums.size()-1);
    }
};