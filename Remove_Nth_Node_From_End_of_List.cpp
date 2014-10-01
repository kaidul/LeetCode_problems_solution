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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(!head or n == 0) return head;
        int count = 0;
        ListNode *iter = head, *removed = head, *prev = nullptr;
        while(iter) {
            count++;
            if(count > n) { prev = removed; removed = removed->next; } 
            iter = iter->next;
        }
        if(prev) prev->next = removed->next;
        else {removed = removed->next; head = removed;}
        return head;
    }
};