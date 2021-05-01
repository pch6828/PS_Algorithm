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
        ListNode* answer = nullptr, *it = nullptr;
        
       map<int, int>cnt;
        
       while(head){
           cnt[head->val]++;
           head = head->next;
       } 
        
        for(auto p:cnt){
            if(p.second==1){
                if(!it){
                    answer = it = new ListNode(p.first);
                }else{
                    it->next = new ListNode(p.first);
                    it = it->next;
                }
            }
        }
        return answer;
    }
};