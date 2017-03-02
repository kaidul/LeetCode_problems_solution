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
public:
     void kthSmallest(TreeNode* root, int& result, int& k) {
        if(!root or k <= 0) return;
        kthSmallest(root->left, result, k);
        if(k == 1) {
            result = root->val;
        }
        k--;
        kthSmallest(root->right, result, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int result;
        kthSmallest(root, result, k);
        return result;
    }
};