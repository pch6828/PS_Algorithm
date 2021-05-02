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
    bool determine(TreeNode* root, int& minimum, int& maximum){
        int temp_min, temp_max;
        
        if(root->left){
            if(!determine(root->left, temp_min, temp_max)){
                return false;
            }
            if(temp_max>=root->val){
                return false;
            }
            minimum = temp_min;
        }else{
            minimum = root->val;
        }
        
        if(root->right){
            if(!determine(root->right, temp_min, temp_max)){
                return false;
            }
            if(temp_min<=root->val){
                return false;
            }
            maximum = temp_max;
        }else{
            maximum = root->val;
        }
        
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        int n, m;
        return determine(root, n, m);
    }
};