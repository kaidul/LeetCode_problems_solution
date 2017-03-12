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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* iter = head;
        ListNode* prev = nullptr;
        while(iter) {
            if(iter->next) {
                ListNode* next2 = iter->next->next;
                iter->next->next = iter;
                if(iter == head) head = iter->next;
                if(prev) prev->next = iter->next;
                iter->next = next2;
                prev = iter;
            }
            iter = iter->next;
        }
        return head;
    }
};