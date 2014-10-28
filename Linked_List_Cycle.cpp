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
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast) {
            fast = fast->next;
            slow = slow->next;
            if(fast) {
                fast = fast->next;
                if(fast == slow) 
                    return true;
            }
        }
        return false;
    }
};
// with extra space
/*
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
*/