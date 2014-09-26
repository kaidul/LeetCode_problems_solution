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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head or !head->next) { return head; }
        ListNode* prev = new ListNode(0);
        prev->next = head;
        head = prev;
        ListNode* iter = head;
                    
        while(iter->next) {
            ListNode *p = iter->next;
            while (p->next and p->val == p->next->val) {
                p = p->next;
            }
            if (p != iter->next) {
                iter->next = p->next;
            }else {
                iter = iter->next;
            }
        }
        return head->next;
    }
};