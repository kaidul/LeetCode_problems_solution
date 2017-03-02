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
    int maxPathSumUtil(TreeNode* root, int& maxPath) {
        if(!root) return 0;
        int leftSum = maxPathSumUtil(root->left, maxPath);
        int rightSum = maxPathSumUtil(root->right, maxPath);
        
        int ret = max(root->val, max(root->val + leftSum, root->val + rightSum));
        maxPath = max(maxPath, max(ret, leftSum + root->val + rightSum));
        
        return ret;
    }
    
public:
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        maxPathSumUtil(root, maxPath);
        return maxPath;
    }
};