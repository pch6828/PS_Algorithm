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
    ListNode* partition(ListNode* head, int x) {
        ListNode* fronthead = nullptr;
        ListNode* fronttail = nullptr;
        ListNode* rearhead = nullptr;
        ListNode* reartail = nullptr;
        
        ListNode* it = head;
        
        while(it!=nullptr){
            if(it->val < x){
                if(!fronthead){
                    fronthead = it;
                    fronttail = it;
                }else{
                    fronttail->next = it;
                    fronttail = it;
                }
            }else{
                if(!rearhead){
                    rearhead = it;
                    reartail = it;
                }else{
                    reartail->next = it;
                    reartail = it;
                }
            }
            it = it->next;
        }
        
        if(!fronthead){
            return rearhead;   
        }
        if(reartail){
            reartail->next = nullptr;
        }
        
        fronttail->next = rearhead;
        return fronthead;
    }
};