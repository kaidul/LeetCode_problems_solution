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
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        unordered_map <ListNode*, bool> visited;
        while(head) {
            if(visited[head])  return true;
            visited[head] = true;
            head = head->next;
        }
        return false;
    }
};