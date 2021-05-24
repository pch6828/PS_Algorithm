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
        void traversal(TreeNode* now, vector<int>& answer){
        if(!now){
            return;
        }
        answer.push_back(now->val);
        traversal(now->left, answer);
        traversal(now->right, answer);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>answer;
        traversal(root, answer);
        return answer;
    }
};