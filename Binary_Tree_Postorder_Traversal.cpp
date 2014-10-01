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
    void postorderTraversalUtils(TreeNode *curr, vector <int> &res) {
        if(curr == NULL) return;
        postorderTraversalUtils(curr->left, res);
        postorderTraversalUtils(curr->right, res);
        res.push_back(curr->val);
    }
    vector<int> postorderTraversal(TreeNode *root) {
        vector <int> result;
        postorderTraversalUtils(root, result);
        return result;
    }
};