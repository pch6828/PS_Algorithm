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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int cnt[20001] = {0,};
        ListNode* answer = nullptr, *it = nullptr;
        for(ListNode*& head:lists){
            while(head){
                cnt[head->val+10000]++;
                head = head->next;
            }
        }
        
        for(int i = 0; i <= 20000; i++){
            while(cnt[i]){
                if(answer){
                    it->next = new ListNode(i-10000);
                    it = it->next;
                }else{
                    answer = it = new ListNode(i-10000);
                }
                cnt[i]--;
            }
        }
        return answer;
    }
};