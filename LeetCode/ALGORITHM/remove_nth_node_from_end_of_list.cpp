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
private:
    ListNode* findAndRemove(ListNode* prev, ListNode* now, int& n, int target){
        if(!(now->next)){
            n++;
        }else{
            findAndRemove(now, now->next, n, target);
            n++;
        }
        if(n==target){
            if(prev){
                prev->next = now->next; 
                return prev;
            }else{
                return now->next;
            }
        }
        return now;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i = 0;
        return findAndRemove(nullptr, head, i, n);
    }
};