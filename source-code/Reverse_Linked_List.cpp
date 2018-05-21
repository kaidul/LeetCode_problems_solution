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
    void reverseListRecur(ListNode* head, ListNode* &head2) {
        if(!head) return;
	int value = head->val;
        reverseListRecur(head->next, head2);
        head2->val = value;
        head2 = head2->next;
    }

    ListNode* reverseList(ListNode* head) {
        // Iteratively
        /*
        stack<int> Stack;
        ListNode *iter = head;
        while(iter) {
            Stack.push(iter->val);
            iter = iter->next;
        }
        iter = head;
        while(!Stack.empty()) {
            iter->val = Stack.top();
            Stack.pop();
            iter = iter->next;
        }
        return head;
        */

        // recursively
        /*
        ListNode *iter = head;
        ListNode *head2 = head;
        reverseListRecur(head2, head);
        return head;
        */

        // O(n) without extra space :)
        if(!head or !head->next) return head;
        ListNode* curr = head;
	ListNode* prev = nullptr;
        ListNode* newHead = nullptr;
        while(curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            newHead = curr;
	    prev = curr;
            curr = nxt;
        }
        return newHead;
    }
};
