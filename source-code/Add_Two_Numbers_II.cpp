/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* newHead = nullptr;
        while(curr) {
            ListNode* next = curr->next;
            curr->next = newHead;
            newHead = curr;
            curr = next;
        }
        return newHead;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode* head = nullptr;
        ListNode* curr = nullptr;
        int carry = 0;
        while(l1 or l2 or carry) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = x + y + carry;
            if(!head) {
                head = new ListNode(sum % 10);
                curr = head;
            } else {
                curr->next = new ListNode(sum % 10);
                curr = curr->next;
            }
            carry = sum / 10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        head = reverseList(head);
        return head;
    }
};

// Without altering/reversing list
class Solution {
    void addTwoNumbers(ListNode* l1, int diff, ListNode* l2, ListNode* curr, ListNode* head, int& carry) {
        
        if(!l1->next and !l2->next) {
            int sum = l1->val + l2->val;
            carry = sum / 10;
            curr->val = sum % 10;
            return;
        }
        curr->next = new ListNode(0);
        if(diff > 0) {
            addTwoNumbers(l1->next, diff - 1, l2, curr->next, head, carry);
        }
        else {
            addTwoNumbers(l1->next, diff, l2->next, curr->next, head, carry);    
        }
        int val1 =  l1->val;
        int val2 =  diff > 0 ? 0 : l2->val;
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        curr->val = sum % 10;
    }
    
    int length(ListNode* head) {
        int len = 0;
        while(head) {
            ++len;
            head = head->next;
        }
        return len;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = length(l1);
        int len2 = length(l2);
        int diff = len1 - len2;
        int carry = 0;
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        if(diff >= 0) {
            addTwoNumbers(l1, diff, l2, curr, head, carry);        
        } else {
            addTwoNumbers(l2, -diff, l1, curr, head, carry); 
        }
        if(carry) {
            ListNode* sentinel = new ListNode(carry);
            sentinel->next = curr;
            curr = sentinel;
        }
        return curr;
    }
};