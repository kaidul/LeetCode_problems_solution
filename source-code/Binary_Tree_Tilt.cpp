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
    int findTilt(TreeNode* root, int& result) {
        if(!root) return 0;
        int leftSum = findTilt(root->left, result);
        int rightSum = findTilt(root->right, result);
        result += abs(leftSum - rightSum);
        
        return (leftSum + root->val + rightSum);
    }
public:
    int findTilt(TreeNode* root) {
        int result = 0;
        findTilt(root, result);
        return result;
    }
};