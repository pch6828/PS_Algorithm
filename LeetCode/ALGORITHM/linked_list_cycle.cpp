/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* it = head;
        while(it){
            if(it->val==INT_MIN){
                return true;
            }
            it->val = INT_MIN;
            it = it->next;
        }
        return false;
    }
};