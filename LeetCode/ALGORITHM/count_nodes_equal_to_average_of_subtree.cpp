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
    int solve(TreeNode *node, int &sum, int &cnt)
    {
        int leftsum = 0, rightsum = 0, leftcnt = 0, rightcnt = 0, ans = 0;
        int avg;

        if (node->left)
        {
            ans += solve(node->left, leftsum, leftcnt);
            sum += leftsum;
            cnt += leftcnt;
        }
        if (node->right)
        {
            ans += solve(node->right, rightsum, rightcnt);
            sum += rightsum;
            cnt += rightcnt;
        }
        sum += node->val;
        cnt++;
        avg = sum / cnt;

        if (node->val == avg)
            ans++;

        return ans;
    }

public:
    int averageOfSubtree(TreeNode *root)
    {
        int sum = 0, cnt = 0;

        return solve(root, sum, cnt);
    }
};