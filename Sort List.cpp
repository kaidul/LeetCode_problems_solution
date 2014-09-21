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
    void MergeSort(ListNode **headRef) {
        ListNode *head = *headRef;
        ListNode *a, *b;
        if(head == NULL or head->next == NULL)
            return;

        FrontBackSplit(head, &a, &b);

        MergeSort(&a);
        MergeSort(&b);

        *headRef = SortedMerge(a, b);
    }

    void FrontBackSplit(struct ListNode* source, struct ListNode** frontRef, struct ListNode** backRef) {

        if(source == NULL or source->next == NULL) {
            *frontRef = source;
            *backRef = NULL;
            return;
        }

        ListNode *fast, *slow;

        slow = source;
        fast = source->next;

        while(fast != NULL) {
            fast = fast->next;
            if(fast != NULL) {
                fast = fast->next;
                slow = slow->next;
            }
        }

        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;

    }

    struct ListNode* SortedMerge(struct ListNode* a, struct ListNode* b) {
        struct ListNode* result = NULL;

        if (a == NULL)
            return(b);
        else if (b == NULL)
            return(a);

        if (a->val <= b->val) {
            result = a;
            result->next = SortedMerge(a->next, b);
        } else {
            result = b;
            result->next = SortedMerge(a, b->next);
        }
        return(result);
    }

    ListNode *sortList(ListNode *head) {
        MergeSort(&head);
        return head;
    }
};