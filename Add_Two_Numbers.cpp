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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *res = NULL, *tail = NULL;
        ListNode *L1 = l1, *L2 = l2;
        int carry = 0;
        int sum = 0;
        while(L1 != NULL or L2 != NULL or carry != 0) {
            int num1 = (L1 == NULL) ? 0 : L1->val;
            int num2 = (L2 == NULL) ? 0 : L2->val;
            sum = num1 + num2 + carry;
            carry = sum / 10;
            sum %= 10;
           
            if(res == NULL) {
               res = new ListNode(sum);
               tail = res;
            } else {
               tail->next = new ListNode(sum);
               tail = tail->next;
            }
            L1 = (L1 == NULL) ? NULL : L1->next;
            L2 = (L2 == NULL)? NULL : L2->next;
       }
       return res;
    }
};