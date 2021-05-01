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
    void deleteNode(ListNode* node) {
        ListNode* it = node, *prev = nullptr;
        while(it->next){
            it->val = it->next->val;
            prev = it;
            it = it->next;
        }
        prev->next = nullptr;
    }
};