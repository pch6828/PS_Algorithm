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
    int getSumAndTilt(TreeNode* root, int& tilt){
        if(!root){
            return 0;
        }
        
        int leftsum = getSumAndTilt(root->left, tilt);
        int rightsum = getSumAndTilt(root->right, tilt);
        
        tilt += abs(leftsum-rightsum);
        
        return root->val+leftsum+rightsum;
    }
public:
    int findTilt(TreeNode* root) {
        int ans = 0;
        getSumAndTilt(root, ans);
        return ans;
    }
};