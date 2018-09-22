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

// Another approach without any helper method
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        if(root->left and (!root->left->left and !root->left->right)) {
            return root->left->val
                + sumOfLeftLeaves(root->right);
        }
        return sumOfLeftLeaves(root->left)
            + sumOfLeftLeaves(root->right);
    }
};