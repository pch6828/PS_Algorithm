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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<pair<int, TreeNode*>>q;
        
        q.push({0, root});
        vector<int>level_size;
        vector<double>answer;
        
        if(!root){
            return answer;
        }
        
        while(!q.empty()){
            auto now = q.front();
            q.pop();
            
            if(now.first == level_size.size()){
                level_size.push_back(0);
                answer.push_back(0);
            }
            level_size.back()++;
            answer.back()+=now.second->val;
            if(now.second->left){
                q.push({now.first+1, now.second->left});
            }
            if(now.second->right){
                q.push({now.first+1, now.second->right});
            }
        }
        
        for(int i = 0; i < answer.size(); i++){
            answer[i]/=level_size[i];
        }
        
        return answer;
    }
};