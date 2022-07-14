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
    TreeNode* constructTree(vector<int>& postorder, vector<int>& inorder, int post_root_idx, int in_start_idx, int in_end_idx){
        if(in_start_idx >in_end_idx){
            return nullptr;
        }
        for(int i = in_start_idx; i <= in_end_idx; i++){
            if(postorder[post_root_idx]==inorder[i]){
                return new TreeNode(inorder[i], 
                                    constructTree(postorder, inorder, post_root_idx-(in_end_idx-i)-1, in_start_idx, i-1),
                                    constructTree(postorder, inorder, post_root_idx-1, i+1, in_end_idx));
            }
        }
        return nullptr;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return constructTree(postorder, inorder, postorder.size()-1, 0, inorder.size()-1);
    }
};
