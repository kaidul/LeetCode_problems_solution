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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(!head or !head->next) return head;
        ListNode *sentinel = new ListNode(0);
        sentinel->next = head;
        int len = 0;
        ListNode *prev = sentinel;
        ListNode *iter = head;
        ListNode *newHead = head;
        bool flag = false;
        while(iter) {
            ++len;
            if(len == k) {
                if(!flag) {
                    newHead = iter;
                    flag = true;
                }
                ListNode *tail = iter;
                ListNode *newHead = tail;
                ListNode *tmp = head;
                while(head != newHead) {
                    ListNode *nxt = tail->next;
                    tail->next = head;
                    head = head->next;
                    tail->next->next = nxt;
                }
                prev->next = head;
                prev = tmp;
                head = prev->next;
                iter = head;
                len = 0;
            } else {
                iter = iter->next;
            }
        }
        return newHead;
    }
};