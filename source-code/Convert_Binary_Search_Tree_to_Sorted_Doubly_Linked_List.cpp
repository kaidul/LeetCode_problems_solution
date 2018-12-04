/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
    void iterateBstLeft(Node* root, stack<Node*>& nodeStack) {
        while (root) {
            nodeStack.push(root);
            root = root->left;
        }
    }
    
    void treeToDoublyList(stack<Node*>& nodeStack, Node*& head, Node*& tail) {
        if (nodeStack.empty()) {
            return;
        }
        Node* currNode = nodeStack.top();
        nodeStack.pop();
        iterateBstLeft(currNode->right, nodeStack);
        currNode->left = currNode->right = nullptr;
        if (!head) {
            head = tail = currNode;
        } else {
            tail->right = currNode;
            currNode->left = tail;
            tail = currNode;
        }
        treeToDoublyList(nodeStack, head, tail);
    }
    
public:
    Node* treeToDoublyList(Node* root) {
        stack<Node*> nodeStack;
        Node* head = nullptr;
        Node* tail = nullptr;
        
        iterateBstLeft(root, nodeStack);
        treeToDoublyList(nodeStack, head, tail);
        if (head) {
            tail->right = head;
            head->left = tail;
        }
        
        return head;
    }
};