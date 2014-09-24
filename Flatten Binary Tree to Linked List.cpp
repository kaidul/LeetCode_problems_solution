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
    /*
    void flattenUtils(TreeNode *newHead, TreeNode *root) {
        if(!root) return;
        newHead->right = new TreeNode(root->val);
        flattenUtils(newHead->right, root->left);
        flattenUtils(newHead->right, root->right);
    }
    void flatten(TreeNode *root) {
        TreeNode *sentinel = new TreeNode(1 << 30);
        flattenUtils(sentinel, root);
        root = sentinel->right;
        delete sentinel;
    }
    */
    void flatten(TreeNode *root) {
        while (root) {
            if (root->left) {
                TreeNode* pre = root->left;
                while (pre->right) { 
                    pre = pre->right;
                }
                pre->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
    }
};