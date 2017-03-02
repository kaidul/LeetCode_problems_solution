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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || n == 0) return head;
        int cnt = 0;
        ListNode* iter = head;
        ListNode* removed = head;
        ListNode* prev = nullptr;
        while(iter) {
            cnt++;
            if(cnt > n) {
                prev = removed;
                removed = removed->next;
            }
            iter = iter->next;
        }
        if(prev) {
            prev->next = removed->next;
        } else {
            removed = removed->next;
            head = removed;
        }
        return head;
    }
};