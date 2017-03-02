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
        if (!head or !head->next) {
            return head;
        }
        ListNode* iter = head;
        while (iter->next) {
            if (iter->next->val == iter->val) {
                iter->next = iter->next->next;
            } else {
                iter = iter->next;
            }
        }
        return head;
    }
};
 // with extra space
 /*
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
*/