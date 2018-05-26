/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // Recursive
class Solution {
public:
    void isPalindrome(ListNode* &head, ListNode* tail, int& i, int j, bool& flag) {
        if(!tail or !flag) return;
        isPalindrome(head, tail->next, i, j + 1, flag);
        if(i > j) return;
        if(head->val != tail->val) {
            flag = false;
        }
        head = head->next;
        i++;
    }
    bool isPalindrome(ListNode* head) {
        int i = 0;
        bool flag = true;
        isPalindrome(head, head, i, 0, flag);
        return flag;
    }
};

// Reverse the middle half of the list and compare
class Solution {
public:
     ListNode* reverseList(ListNode* head) {
        if(!head and !head->next) {
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = nullptr;
         while(curr) {
             ListNode* nxt = curr->next;
             curr->next = prev;
             prev = curr;
             head = curr;
             curr = nxt;
         }
        return head;
    }

    bool isPalindrome(ListNode* head) {
        if(!head or !head->next) {
            return true;
        }
        int length = 0;
        ListNode* curr = head;
        while(curr) {
            ++length;
            curr = curr->next;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast) {
            slow = slow->next;
            fast = fast->next;
            if(fast) {
                fast = fast->next;
            } 
        }
        if(length & 1) {
            slow = slow->next;
        }
        ListNode* secondHalf = reverseList(slow);
        
        while(head and secondHalf) {
            if(head->val != secondHalf->val) {
                return false;
            }
            head = head->next;
            secondHalf = secondHalf->next;
        }
        return true;
    }
};