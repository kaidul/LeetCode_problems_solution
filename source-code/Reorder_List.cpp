/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        fast = fast->next;
        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
            if(fast->next) {
                fast = fast->next;
            }
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* iter = head;
        ListNode* prev = nullptr;
        while(iter) {
            ListNode* next = iter->next;
            iter->next = prev;
            prev = iter;
            head = iter;
            iter = next;
        }
        return head;
    }
    
public:
    void reorderList(ListNode* head) {
        if(!head or !head->next or !head->next->next) {
            return;
        }
        ListNode* mid = findMid(head);
        ListNode* head2 = mid->next;
        mid->next = nullptr;
        head2 = reverseList(head2);
        ListNode* backup = head;
        while(head2) {
            ListNode* next = head->next;
            head->next = head2;
            ListNode* next2 = head2->next;
            head2->next = next;
            
            head = next;
            head2 = next2;
        }
        head = backup;
    }
};