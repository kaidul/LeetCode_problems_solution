/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int longestUnivaluePath(TreeNode* root, int val) {
        if(!root or root->val != val) return 0;
        return 1 + max(longestUnivaluePath(root->left, val), longestUnivaluePath(root->right, val));
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        int sub = max(longestUnivaluePath(root->left), longestUnivaluePath(root->right));
        return max(sub, longestUnivaluePath(root->left, root->val) + longestUnivaluePath(root->right, root->val));
    }
};