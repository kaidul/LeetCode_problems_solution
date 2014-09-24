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
    void reorderList(ListNode *head) {
        if(!head) { return; }
        ListNode *slow = head, *fast = nullptr;
        if(head->next == nullptr) { return; }
        fast = head->next;
        if(head->next->next == nullptr) { return; }
        if(fast) while(fast->next) {
            fast = fast->next;
            slow = slow->next;
            if(fast->next) fast = fast->next;
        }
        ListNode *tmp = slow->next;
        slow->next = nullptr;
        ListNode *head2 = tmp;
        tmp = tmp->next;
        head2->next = nullptr;
        while(tmp) {
            ListNode *tmp2 = tmp->next;
            tmp->next = head2;
            head2 = tmp;
            tmp = tmp2;
        }
        ListNode *backup = head, *iter = head;
        head = head->next;
        while(head2) {
            iter->next = head2;
            iter = iter->next;
            head2 = head2->next;

            if(head) {
                iter->next = head;
                iter = iter->next;
                head = head->next;
            }
        }
        head = backup;
    }
};