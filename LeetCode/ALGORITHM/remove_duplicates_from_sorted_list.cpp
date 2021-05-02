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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *it = head;
        
        while(it){
            ListNode* next = it->next;
            while(next && next->val==it->val){
                next = next->next;
            }
            it->next = next;
            it = it->next;
        }
        return head;
    }
};