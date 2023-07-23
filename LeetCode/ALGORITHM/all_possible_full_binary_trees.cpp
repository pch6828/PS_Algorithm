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
map<int, vector<TreeNode*>>memo;
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*>ans;
        if(n%2==0){
            return ans;
        }
        else if(memo.count(n)){
            return memo[n];
        }
        else if(n==1){
            ans.push_back(new TreeNode());
            memo[n] = ans;
            return memo[n];
        }
        for(int i = 1; i < n; i+=2){
            int l = i;
            int r = n - 1 - l;

            const vector<TreeNode*>&left_child = allPossibleFBT(l);
            const vector<TreeNode*>&right_child = allPossibleFBT(r);
            for(TreeNode* left : left_child){
                for(TreeNode* right : right_child){
                    ans.push_back(new TreeNode(0, left, right));
                }
            }
        }
        memo[n] = ans;
        return memo[n];
    }
};