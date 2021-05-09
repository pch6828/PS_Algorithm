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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode* it;
        it = headA;
        while(it){
            it = it->next;
            lenA++;
        }
        it = headB;
        while(it){
            it = it->next;
            lenB++;
        }
        while(lenA<lenB){
            lenB--;
            headB = headB->next;
        }
        while(lenA>lenB){
            lenA--;
            headA = headA->next;
        }
        while(headA&&headB){
            if(headA==headB){
                return headA;
            }    
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};