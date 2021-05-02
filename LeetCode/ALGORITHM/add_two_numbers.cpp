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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        
        ListNode* answer = nullptr, *it = nullptr;
        while(l1||l2){
            int a = l1?l1->val:0;
            l1 = l1?l1->next:l1;
            int b = l2?l2->val:0;
            l2 = l2?l2->next:l2;
            
            int sum = a+b+carry;
            carry = sum/10;
            if(it){
                it->next = new ListNode(sum%10);
                it = it->next;
            }else{
                answer = new ListNode(sum%10);
                it = answer;
            }
        }
        if(carry){
            it->next = new ListNode(carry);
            it = it->next;
        }
        return answer;
    }
};