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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* answer = nullptr;
        ListNode* a = nullptr;
        ListNode* b = nullptr;
        ListNode* c = nullptr;
        ListNode* it = head;
        int i = 1;
        
        while(it && i < left){
            if(!a){
                answer = a = it;
            }else{
                a->next = it;
                a = a->next;
            }
            i++;
            it = it->next;
        }
        
        while(it && i <= right){
            if(!b){
                b = c = new ListNode(it->val);
            }else{
                b = new ListNode(it->val, b);
            }
            i++;
            it = it->next;
        }
        
        while(it){
            c->next = it;
            c = c->next;
            it = it->next;
        }
        
        if(a){
            a->next = b;
        }else{
            answer = b;
        }
        return answer;
        
    }
};