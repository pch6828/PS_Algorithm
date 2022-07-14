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
    string pathToString(vector<int>&path){
        string ans;
        ans+=to_string(path[0]);
        for(int i = 1; i < path.size(); i++){
            ans+="->";
            ans+=to_string(path[i]);
        }
        return ans;
    }    
    void dfs(TreeNode* root, vector<string>&result, vector<int>&path){
        path.push_back(root->val);
        if(root->left){
            dfs(root->left, result, path);
        }
        if(root->right){
            dfs(root->right, result, path);
        }
        
        if(!root->left&&!root->right){
            result.push_back(pathToString(path));
        }
        path.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int>path;
        vector<string>ans;
        dfs(root, ans, path);
        
        return ans;
    }
};