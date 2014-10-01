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
    int maxDepth(TreeNode * root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
     
    bool isBalanced(TreeNode *root) {
        if (!root) return true;
        if (abs(maxDepth(root->left) - maxDepth(root->right)) > 1) return false;
        return (isBalanced(root->left) and isBalanced(root->right));
    }
     
};