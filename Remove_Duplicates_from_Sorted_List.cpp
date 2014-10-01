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
        if(!head) return head;
        unordered_map <int, bool> Map;
        ListNode *sentinel = new ListNode(1 << 30);
        sentinel->next = head;
        ListNode *iter = head, *prev = sentinel;
        while(iter) {
            if(Map[iter->val]) {
                ListNode *tmp = iter;
                prev->next = iter->next;
                iter = iter->next;
                delete tmp;
            } else {
                Map[iter->val] = true;
                prev = iter;
                iter = iter->next;
            }
        }
        return head;
    }
};