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
    void dfs(vector<int>& ans, TreeNode* now, int depth){
        if(!now) return;
        if(ans.size()==depth){
            ans.push_back(now->val);
        }else{
            ans[depth] = now->val;
        }
        
        dfs(ans, now->left, depth+1);
        dfs(ans, now->right, depth+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        dfs(ans, root, 0);
        return ans;
    }
};