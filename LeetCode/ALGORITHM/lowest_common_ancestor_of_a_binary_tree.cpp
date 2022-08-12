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
    bool findAndBuildStack(stack<TreeNode*>&s, TreeNode* target, TreeNode* it){
        s.push(it);
        if(it==target){
            return true;
        }
        if(it->left!=nullptr){
            if(findAndBuildStack(s, target, it->left)){
                return true;
            }
        }
        if(it->right!=nullptr){            
            if(findAndBuildStack(s, target, it->right)){
                return true;
            }
        }
        s.pop();
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*>a, b;
        
        findAndBuildStack(a, p, root);
        findAndBuildStack(b, q, root);
        
        while(a.size()>b.size()){
            a.pop();
        }
        while(b.size()>a.size()){
            b.pop();
        }
        while(a.top()!=b.top()){
            a.pop();
            b.pop();
        }
        return a.top();
    }
};

