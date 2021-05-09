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
    ListNode* middleNode(ListNode* head) {
        ListNode* it = head;
        int len = 0;
        while(it){
            it = it->next;
            len++;
        }
        int mid = len/2;
        it = head;
        while(mid--){
            it = it->next;
        }
        return it;
    }
};