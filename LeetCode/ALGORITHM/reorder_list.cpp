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
    void reorderList(ListNode* head) {
        ListNode* it = head;
        deque<int>dq;
        while(it){
            dq.push_back(it->val);
            it = it->next;
        }
        it = head;
        bool flag = true;
        while(dq.size()){
            if(flag){
                it->val = dq.front();
                dq.pop_front();
            }else{
                it->val = dq.back();
                dq.pop_back();
            }
            flag = !flag;
            it = it->next;
        }
    }
};