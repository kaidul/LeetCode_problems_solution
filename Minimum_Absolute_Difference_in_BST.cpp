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
    int getMinimumDifference(TreeNode* root, int& prev) {
        if(!root) return INT_MAX;
        int leftMin = getMinimumDifference(root->left, prev);
        int diff = (prev == INT_MIN) ? INT_MAX : root->val - prev;
        prev = root->val;
        int rightMin = getMinimumDifference(root->right, prev);
        
        return min(diff, min(leftMin, rightMin));
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int prev = INT_MIN;
        return getMinimumDifference(root, prev);
    }
};