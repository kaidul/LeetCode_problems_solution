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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(!l1 and !l2) return l1;
        if(l1 and !l2) return l1;
        if(!l1 and l2) return l2;
        ListNode *head;
        ListNode *sentinel = new ListNode(1 << 30);
        head = sentinel;
        while(l1 and l2) {
            if(l1->val <= l2->val) {
                head->next = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        while(l1) {
            head->next = l1;
            l1 = l1->next;
            head = head->next;
        }
        while(l2) {
            head->next = l2;
            l2 = l2->next;
            head = head->next;
        }
        return sentinel->next;
    }
};