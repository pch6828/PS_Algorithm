/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool hasPath(ListNode *head, TreeNode *root)
    {
        if (!head)
            return true;
        if (head && root && head->val == root->val)
        {
            return hasPath(head->next, root->left) || hasPath(head->next, root->right);
        }
        return false;
    }

public:
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        if (hasPath(head, root))
            return true;
        if (root)
        {
            if (isSubPath(head, root->left))
                return true;
            else if (isSubPath(head, root->right))
                return true;
        }
        return false;
    }
};