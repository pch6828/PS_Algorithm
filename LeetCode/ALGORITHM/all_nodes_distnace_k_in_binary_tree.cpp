/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void find_distanceK_from_root(TreeNode* root, int k, vector<int>&ans){
        if(k < 0)
            return;
        else if(k==0){
            ans.push_back(root->val);
            return;
        }
        if(root->left)
            find_distanceK_from_root(root->left, k-1, ans);
        if(root->right)
            find_distanceK_from_root(root->right, k-1, ans);
    }
    bool dfs(TreeNode* root, int target, int& k, vector<int>& ans) {
        if(root->val == target) {
            find_distanceK_from_root(root, k, ans);
            return true;
        }

        if(root->left){
            if(dfs(root->left, target, k, ans)){
                k--;
                if(!k)
                    ans.push_back(root->val);
                else if(root->right)
                    find_distanceK_from_root(root->right, k-1, ans);
                return true;
            }
        }
        if(root->right){
            if(dfs(root->right, target, k, ans)){
                k--;                
                if(!k)
                    ans.push_back(root->val);
                else if(root->left)
                    find_distanceK_from_root(root->left, k-1, ans);
                return true;
            }
        }
        return false;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        dfs(root, target->val, k, ans);

        return ans;
    }
};