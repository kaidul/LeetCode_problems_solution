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
    void inorderTraversalUtils(TreeNode *curr, vector <int> &res) {
        if(curr == NULL) return;
        inorderTraversalUtils(curr->left, res);
        res.push_back(curr->val);
        inorderTraversalUtils(curr->right, res);
    }
    vector<int> inorderTraversal(TreeNode *root) {
        vector <int> result;
        inorderTraversalUtils(root, result);
        return result;
    }
};