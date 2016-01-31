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
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        if (root->left and root->right) {
            int left = 1 + minDepth(root->left);
            int right = 1 + minDepth(root->right);
            return min(left, right);
        }
        
        if (root->left) {
            return 1 + minDepth(root->left);
        }
        if (root->right) {
            return 1 + minDepth(root->right);
        }
        return 1; // both NULL
    }
};