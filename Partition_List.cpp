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
    ListNode *partition(ListNode *head, int x) {
        if(!head) return head;
        ListNode *sentinel = new ListNode(numeric_limits<int>::max());
        sentinel->next = head;
        ListNode *iter = head;
        ListNode *boundary = nullptr, *tail = sentinel;
        while(iter) {
            if(iter->val >= x) {
                boundary = iter;
                break;
            }
            tail = iter;
            iter = iter->next;
        }
        if(!boundary) return head;
        iter = boundary->next;
        ListNode *prev = boundary;
        while(iter) {
            if(iter->val < x) {
                prev->next = iter->next;
                ListNode *tmp = iter;
                iter = iter->next;
                tmp->next = boundary;
                tail->next = tmp;
                tail = tmp;
            } else {
                prev = iter;
                iter = iter->next;
            }
        }
        if(head != boundary) return head;
        return sentinel->next;
    }
};