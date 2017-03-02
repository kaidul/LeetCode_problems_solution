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
    int robUtil(TreeNode* root, int& nxt) {
        if(!root) { nxt = 0; return 0; }
        
        int nxt1 = 0, nxt2 = 0;
        int leftSum = robUtil(root->left, nxt1);
        int rightSum = robUtil(root->right, nxt2);
        
        nxt = max(leftSum, nxt1) + max(rightSum, nxt2);
        return nxt1 + root->val + nxt2;
    }
public:
    int rob(TreeNode* root) {
        int result2;
        int result = robUtil(root, result2);
        return max(result, result2);
    }
};

// return using pair
class Solution {
    pair<int, int> robUtil(TreeNode* root) {
        if(!root) { return {0, 0}; }
        
        auto leftSum = robUtil(root->left);
        auto rightSum = robUtil(root->right);
        
        return {leftSum.second + root->val + rightSum.second, max(leftSum.first, leftSum.second) + max(rightSum.first, rightSum.second)};
    }
public:
    int rob(TreeNode* root) {
        pair<int, int> result = robUtil(root);
        return max(result.first, result.second);
    }
};
