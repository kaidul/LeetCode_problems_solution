/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        while (root) {
            TreeLinkNode* sentinel = new TreeLinkNode(INT_MIN);
            TreeLinkNode* currNode = sentinel;
            while (root) {
                if (root->left) {
                    currNode->next = root->left;
                    currNode = currNode->next;
                }
                if (root->right) {
                    currNode->next = root->right;
                    currNode = currNode->next;
                }
                root = root->next;
            }
            root = sentinel->next;
        }
    }
};

// using recursion in inorder fashion
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        
        flatten(root->left);
        
        TreeNode* right = root->right;
        root->right = root->left;
        root->left = nullptr;
        while(root->right) {
            root = root->right;
        }
        root->right = right;
        
        flatten(right);
    }
};