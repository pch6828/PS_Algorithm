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
    pair<TreeNode*, TreeNode*>tree_to_list(TreeNode* root){
        TreeNode* head = root;
        TreeNode* tail = root;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        tail->left = tail->right = nullptr;
        cout<<root->val<<endl;
        if(left){
            auto left_result = tree_to_list(left);
            tail->right = left_result.first;
            tail = left_result.second;
        }
        if(right){
            auto right_result = tree_to_list(right);
            tail->right = right_result.first;
            tail = right_result.second;
        }
        
        return {head, tail};
    } 
    
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }
        
        auto result = tree_to_list(root);
    }
};