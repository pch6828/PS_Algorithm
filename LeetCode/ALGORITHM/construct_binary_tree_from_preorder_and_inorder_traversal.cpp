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
    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder, int pre_root_idx, int in_start_idx, int in_end_idx){
        if(in_start_idx >in_end_idx){
            return nullptr;
        }
        for(int i = in_start_idx; i <= in_end_idx; i++){
            if(preorder[pre_root_idx]==inorder[i]){
                return new TreeNode(inorder[i], 
                                    constructTree(preorder, inorder, pre_root_idx+1, in_start_idx, i-1),
                                    constructTree(preorder, inorder, pre_root_idx+(i-in_start_idx)+1, i+1, in_end_idx));
            }
        }
        return nullptr;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return constructTree(preorder, inorder, 0, 0, inorder.size()-1);
    }
};