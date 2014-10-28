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
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) {
                break;
            }
        }
        
        if(!fast or !fast->next)
            return nullptr;

        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return fast;
    }
};

// with extra space
/*
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return head;
        unordered_map <ListNode*, bool> visited;
        // ListNode *prev = NULL;
        while(head) {
            if(visited[head]) {
                return head;
            }
            visited[head] = true;
            head = head->next;
        }
        return NULL;
    }
};
*/