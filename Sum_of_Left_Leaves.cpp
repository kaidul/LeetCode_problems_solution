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
    int sumOfLeftLeavesRecur(TreeNode* root, bool isLeft) {
        if(!root) return 0;
        if(!root->left and !root->right and isLeft) return root->val;
        return sumOfLeftLeavesRecur(root->left, true) + sumOfLeftLeavesRecur(root->right, false);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeftLeavesRecur(root, false);
    }
};