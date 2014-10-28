/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBSTUtils(ListNode *head) {
        if(head == nullptr) {
            return nullptr;
        }
        ListNode *slow = head, *fast = head->next;
        ListNode *tail = nullptr;
        while(fast) {
            fast = fast->next;
            tail = slow;
            slow = slow->next;
            if(fast) fast = fast->next;
        }
        ListNode *middle = slow;
        if(tail) tail->next = nullptr;
        if(head == middle) head = nullptr;
        
        TreeNode *node = new TreeNode(middle->val);
        node->left = sortedListToBSTUtils(head);
        node->right = sortedListToBSTUtils(middle->next);
        return node;
    }
    
    TreeNode *sortedListToBST(ListNode *head) {
        return sortedListToBSTUtils(head);
    }
};