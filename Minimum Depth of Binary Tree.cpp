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
        if (root == NULL) {
            return 0;
        }
        
        if (root->left != NULL and root->right != NULL) {
            int left = 1 + minDepth(root->left);
            int right = 1 + minDepth(root->right);
            return left < right ? left : right; 
        }
        
        if (root->left != NULL) {
            return 1 + minDepth(root->left);
        }
        if (root->right != NULL) {
            return 1 + minDepth(root->right);
        }
        return 1; // both NULL
    }
};