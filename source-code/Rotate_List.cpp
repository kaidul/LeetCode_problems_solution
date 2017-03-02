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
    ListNode *rotateRight(ListNode *head, int k) {
        
        if(!head or k < 1) return head;
        
        int len = 0;
        ListNode *iter = head, *tail = head;
        while(iter) {
            len++;
            tail = iter;
            iter = iter->next;
        }
        
        iter = head;
        k %= len;
        if(k == 0) return head;
        int cutPoint = len - k;
        int i = 0;
        while(i < cutPoint - 1) {
            ++i;
            iter = iter->next;
        }

        ListNode *newHead = iter->next;
        iter->next = NULL;
        tail->next = head;
        head = newHead;
        return head;
    }
};