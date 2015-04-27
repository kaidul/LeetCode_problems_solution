/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA, *pB;
        pA = headA, pB = headB;
        while(pA and pB) {
            pA = pA->next;
            pB = pB->next;
        }
        if(pA and !pB) return getIntersectionNode(headB, headA);
        ListNode *pB2 = headB;
        while(pB) {
            pB = pB->next;
            pB2 = pB2->next;
        }
        pA = headA, pB = pB2;
        while(pA and pB and pA != pB) {
            pA = pA->next;
            pB = pB->next;
        }
        return pA;
    }
};
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return NULL;
 
        ListNode *na = headA, *nb = headB;

        // O(n + m)
        traverseAndRedirect(na,nb,headA,headB); 
        traverseAndRedirect(na,nb,headA,headB);
 
        while (na && nb && na != nb) {
            na = na->next;
            nb = nb->next;
        }
 
        return na;
    }
 
    void traverseAndRedirect(ListNode* &na, ListNode* &nb, ListNode* &headA, ListNode* &headB) {
        while (na && nb) {
            na = na->next;
            nb = nb->next;
        }
 
        if (!na) {
            na = headB;
        } else if (!nb) {
            nb = headA;
        }
    }
};