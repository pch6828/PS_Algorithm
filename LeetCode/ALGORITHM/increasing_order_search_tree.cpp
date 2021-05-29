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
    TreeNode* answer = nullptr;
    TreeNode* it = nullptr;
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(!root){
            return answer;
        }
        increasingBST(root->left);
        if(!answer){
            answer = it = new TreeNode(root->val);
        }else{
            it->right = new TreeNode(root->val);
            it = it->right;
        }
        increasingBST(root->right);
        return answer;
    }
};