/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    void plusOneRecur(ListNode* curr, ListNode* head, ListNode* sentinel, int& carry) {
        if(!curr->next) {
            curr->val++;
            carry = curr->val / 10;
            curr->val %= 10;
            if(curr == head) {
                if(carry > 0) {
                    sentinel->val += carry;
                }
            }
            return;
        }
        plusOneRecur(curr->next, head, sentinel, carry);
        if(!carry) {
            return;
        }
        curr->val += carry;
        carry = curr->val / 10;
        curr->val %= 10;
        
        if(curr == head) {
            if(carry > 0) {
                sentinel->val += carry;
            }
        }
    }
public:
    ListNode* plusOne(ListNode* head) {
        if(!head) return head;
        ListNode* sentinel = new ListNode(0);
        sentinel->next = head;
        int carry = 0;
        plusOneRecur(head, head, sentinel, carry);
        return ((sentinel->val > 0) ? sentinel : head);
    }
};