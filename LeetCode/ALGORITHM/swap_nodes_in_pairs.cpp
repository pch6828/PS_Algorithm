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
    ListNode* swapPairs(ListNode* head) {
        ListNode* tail = NULL;
        ListNode* newhead = NULL;

        if(!head || !head->next)
            return head;
        
        while(head && head->next){
            ListNode* a = head;
            ListNode* b = head->next;
            head = head->next->next;

            if(!newhead)
                newhead = b;
            else
                tail->next = b;
            
            b->next = a;
            a->next = head;
            tail = a;
        }

        return newhead;
    }
};