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
    void traversal(TreeNode* tree, map<int, int>& cnt){
        if(!tree){
            return;
        }
        traversal(tree->left, cnt);
        cnt[tree->val]++;
        traversal(tree->right, cnt);
    }
    vector<int> findMode(TreeNode* root) {
        map<int, int>cnt;
        
        traversal(root, cnt);
        
        int mode_cnt = 0;
        vector<int>answer;
        
        for(auto p : cnt){
            if(mode_cnt<p.second){
                answer.clear();
                answer.push_back(p.first);
                mode_cnt = p.second;
            }else if(mode_cnt==p.second){
                answer.push_back(p.first);
            }
        }
        return answer;
    }
};