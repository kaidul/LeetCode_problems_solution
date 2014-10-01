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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return head;
        unordered_map <ListNode*, bool> visited;
        // ListNode *prev = NULL;
        while(head) {
            if(visited[head]) {
                // return prev;
                return head;
            }
            visited[head] = true;
            // prev = head;
            head = head->next;
        }
        return NULL;
    }
};