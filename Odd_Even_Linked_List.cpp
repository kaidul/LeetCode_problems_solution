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
    ListNode* oddEvenList(ListNode* head) {
        if(!head or !head->next or !head->next->next)
            return head;
        ListNode* pOdd = head;
        ListNode* pEven = head->next;
        ListNode* prev = head->next;
        ListNode* iter = head->next->next;
        int odd = 1;
        while(iter) {
            ListNode* nxt = iter->next;
            if(odd) {
                prev->next = iter->next;
                pOdd->next = iter;
                pOdd = pOdd->next;
                prev = prev->next;
            }
            iter = nxt;
            odd ^= 1;
        }
        pOdd->next = pEven;
        
        return head;
    }
};