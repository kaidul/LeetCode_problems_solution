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
    void preorderTraversalUtils(TreeNode *curr, vector <int> &res) {
        if(curr == NULL) return;
        res.push_back(curr->val);
        preorderTraversalUtils(curr->left, res);
        preorderTraversalUtils(curr->right, res);
    }
    vector<int> preorderTraversal(TreeNode *root) {
        vector <int> result;
        preorderTraversalUtils(root, result);
        return result;
    }
};