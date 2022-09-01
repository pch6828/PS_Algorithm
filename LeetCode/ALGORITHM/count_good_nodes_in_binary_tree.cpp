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
    void dfs(TreeNode* root, int& cnt, int max_from_path){
        if(!root){
            return;
        }
        if(root->val>=max_from_path){
            cnt++;
        }
        dfs(root->left, cnt, max(max_from_path, root->val));
        dfs(root->right, cnt, max(max_from_path, root->val));
    }
    
public:
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        dfs(root, cnt, root->val);
        return cnt;
    }
};