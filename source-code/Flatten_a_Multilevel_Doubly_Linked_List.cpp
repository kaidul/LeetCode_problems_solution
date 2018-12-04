/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/

/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
// in-place
class Solution {
    void flatten(Node* head, Node*& tail) {
        if (!head) {
            return;
        }
        if (!head->child and !head->next) {
            tail = head;
            return;
        }
        Node* next = head->next;
        if (head->child) {
            head->next = head->child;
            head->child->prev = head;
            head->child = nullptr;
            
            flatten(head->next, tail);
            
            assert(tail);
            tail->next = next;
            if(next) {
                next->prev = tail;    
            }
        }
        flatten(next, tail);
    }
public:
    Node* flatten(Node* head) {
        Node* tail = head;
        flatten(head, tail);
        return head;
    }
};

// solution with deep copy
class Solution {
    void appendNode(Node*& curr, Node* node) {
        curr->next = new Node(node->val, curr, nullptr, nullptr);
        curr = curr->next;
    }

    void flatten(Node* head, Node*& curr) {
        if (!head) {
            return;
        }
        if (head->child) {
            appendNode(curr, head->child);
            flatten(head->child, curr);
        }
        if (head->next) {
            appendNode(curr, head->next);
            flatten(head->next, curr);
        } 
    }
public:
    Node* flatten(Node* head) {
        if (!head) return head;
        Node* newHead = new Node();
        newHead->val = head->val;
        Node* curr = newHead;
        flatten(head, curr);
        return newHead;
    }
};