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