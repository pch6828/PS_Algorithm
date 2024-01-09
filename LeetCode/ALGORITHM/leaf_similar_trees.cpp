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
private:
    void get_leaves(TreeNode *node, vector<int> &vec)
    {
        if (node->left)
            get_leaves(node->left, vec);
        if (!node->left && !node->right)
            vec.push_back(node->val);
        if (node->right)
            get_leaves(node->right, vec);
    }

public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> a, b;
        get_leaves(root1, a);
        get_leaves(root2, b);

        return a == b;
    }
};