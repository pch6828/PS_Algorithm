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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head){
            return nullptr;
        }
        queue<ListNode*>q;
        while(head){
            q.push(head);
            head = head->next;
        }
        k %= q.size();
        k = q.size()-k;
        
        while(k--){
            q.push(q.front());
            q.pop();
        }
        
        ListNode* answer = q.front(), *it = answer;
        q.pop();
        
        while(!q.empty()){
            it->next = q.front();
            it = it->next;
            it->next = nullptr;
            q.pop();
        }
        
        return answer;
    }
};