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
    int maxAncestorDiff(TreeNode *root, int M = INT_MIN, int m = INT_MAX)
    {
        int ans = 0;

        M = max(M, root->val);
        m = min(m, root->val);

        ans = M - m;
        if (root->left)
            ans = max(ans, maxAncestorDiff(root->left, M, m));
        if (root->right)
            ans = max(ans, maxAncestorDiff(root->right, M, m));

        return ans;
    }
};