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
    bool isReflected(TreeNode* a, TreeNode* b){
        if((!a&&!b)){
            return true;
        }
        if((a&&!b)||(!a&&b)){
            return false;
        }
        return a->val==b->val&&isReflected(a->left, b->right)&&isReflected(a->right, b->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isReflected(root->left, root->right);
    }
};