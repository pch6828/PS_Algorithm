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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* answer = nullptr, *it = nullptr;
        while(head){
            if(head->val!=val){
                if(!answer){
                    answer = it = new ListNode(head->val);
                }else{
                    it->next = new ListNode(head->val);
                    it = it->next;
                }
            }
            head = head->next;
        }
        return answer;
    }
};