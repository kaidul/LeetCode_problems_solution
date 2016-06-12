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
    void reverseListRecur(ListNode* &head, ListNode* tail, int &cnt) {
        if(!tail) return;
        reverseListRecur(head, tail->next, cnt);
        if(cnt <= 0) return;
        swap(head->val, tail->val);
        head = head->next;
        cnt--;
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
        int cnt = 0;
        while(iter) {
            ++cnt;
            iter = iter->next;
        }
        cnt /= 2;
        ListNode *head2 = head;
        reverseListRecur(head2, head, cnt);
        return head;
        */

        // O(n) without extra space :)
        if(!head or !head->next) return head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
};