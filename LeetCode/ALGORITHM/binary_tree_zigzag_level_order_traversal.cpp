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
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        stack<TreeNode *> q[2];
        vector<vector<int>> ans;
        int idx = 0;

        if (root)
            q[idx].push(root);

        while (!q[idx % 2].empty())
        {
            vector<int> temp;
            while (!q[idx % 2].empty())
            {
                TreeNode *node = q[idx % 2].top();
                q[idx % 2].pop();
                temp.push_back(node->val);
                if (idx % 2 == 0)
                {
                    if (node->right)
                        q[(idx + 1) % 2].push(node->right);
                    if (node->left)
                        q[(idx + 1) % 2].push(node->left);
                }
                else
                {
                    if (node->left)
                        q[(idx + 1) % 2].push(node->left);
                    if (node->right)
                        q[(idx + 1) % 2].push(node->right);
                }
            }
            idx++;
            ans.push_back(temp);
        }
        return ans;
    }
};