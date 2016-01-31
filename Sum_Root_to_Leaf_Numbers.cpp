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
 
    void dfs(TreeNode* root, int cur, int &res) {
        if (!root->left and !root->right) {
            cur = cur * 10 + root->val;
            res += cur;
            return;
        }
        cur = cur * 10 + root->val;
        if (root->left) {
            dfs(root->left, cur, res);
        }
        if (root->right) {
            dfs(root->right, cur, res);
        }
    }
    
    int sumNumbers(TreeNode *root) {
        int res = 0;
        if (!root) { return res; }
        dfs(root, 0, res);
        return res;
    }
};