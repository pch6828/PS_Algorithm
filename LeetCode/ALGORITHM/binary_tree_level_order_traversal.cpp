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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<int, TreeNode*>>q;
        
        q.push({0, root});
        vector<vector<int>>answer;
        
        if(!root){
            return answer;
        }
        
        while(!q.empty()){
            auto now = q.front();
            q.pop();
            
            if(now.first == answer.size()){
                answer.push_back(vector<int>());
            }
            answer.back().push_back(now.second->val);
            if(now.second->left){
                q.push({now.first+1, now.second->left});
            }
            if(now.second->right){
                q.push({now.first+1, now.second->right});
            }
        }
        
        return answer;
    }
};