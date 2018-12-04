/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            head = new Node();
            head->val = insertVal;
            head->next = head;
            return head;
        }
        
        Node* curr = head;
        Node* tail = nullptr;
        do {
            if (!tail or (curr->val > tail->val)) {
                tail = curr;
            }
            if (insertVal >= curr->val and curr->next and insertVal <= curr->next->val) {
                curr->next = new Node(insertVal, curr->next);
                return head;
            }
            curr = curr->next;
        } while (curr and curr != head);
        
        tail->next = new Node(insertVal, tail->next);
        
        return head;
    }
};