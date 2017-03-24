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
    void convertBST(TreeNode* root, int& add) {
        if(!root) return;
        convertBST(root->right, add);
        root->val += add;
        add = root->val;
        convertBST(root->left, add);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        convertBST(root, sum);
        return root;
    }
};