/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(!head or !(head->next)) return head;
        ListNode *iter = head;
        ListNode *prev = nullptr;
        while(iter) {
            if(iter->next) {
                ListNode *tmp = iter->next;
                if(tmp == head->next) head = tmp;
                iter->next = tmp->next;
                tmp->next = iter;
                if(prev) prev->next = tmp;
            }
            prev = iter;
            iter = iter->next;
        }
        return head;
    }
};