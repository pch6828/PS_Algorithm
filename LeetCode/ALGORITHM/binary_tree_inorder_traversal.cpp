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
    void traversal(TreeNode* tree, vector<int>& answer){
        if(!tree){
            return;
        }
        traversal(tree->left, answer);
        answer.push_back(tree->val);
        traversal(tree->right, answer);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>answer;
        traversal(root, answer);
        return answer;
    }
};