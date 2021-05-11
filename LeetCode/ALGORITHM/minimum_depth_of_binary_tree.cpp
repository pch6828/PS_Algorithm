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
int answer = INT_MAX;
public:
    void dfs(TreeNode* now, int depth){
        int child = 0;
        if(now->left){
            child++;
            dfs(now->left, depth+1);
        }
        if(now->right){
            child++;
            dfs(now->right, depth+1);
        }
        if(!child){
            answer = min(depth, answer);
        }
    }
    
    int minDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        dfs(root, 1);
        return answer;
    }
};