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
    bool isPalindrome(ListNode* head) {
        int len = 0;
        ListNode *it = head, *tail = nullptr;
        while(it){
            len++;
            it = it->next;
        }
        int mid = len/2;
        it = head;
        while(mid--){
            ListNode* temp = it;
            it = it->next;
            temp->next = tail;
            tail = temp;
        }
        if(len%2){
            it = it->next;
        }
        head = it;
        while(tail&&head){
            if(tail->val!=head->val){
                return false;
            }
            tail = tail->next;
            head = head->next;
        }
        
        return true;
    }
};