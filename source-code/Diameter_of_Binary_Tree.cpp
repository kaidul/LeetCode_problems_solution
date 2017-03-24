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
    int diameterOfBinaryTree(TreeNode* node, int& diameter) {
        if(!node) return 0;
        int leftDepth = diameterOfBinaryTree(node->left, diameter);
        int rightDepth = diameterOfBinaryTree(node->right, diameter);
        
        diameter = max(diameter, leftDepth + rightDepth);
        
        return 1 + max(leftDepth, rightDepth);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        diameterOfBinaryTree(root, diameter);
        
        return diameter;
    }
};