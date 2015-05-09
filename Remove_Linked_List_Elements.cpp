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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        ListNode *sentinel = new ListNode(1 << 30);
        sentinel->next = head;
        ListNode *prev = sentinel; 
        while(head) {
            if(head->val == val) {
                prev->next = head->next;
            } else {
                prev= head;   
            }
            head = head->next;
        }
        return sentinel->next;
    }
};