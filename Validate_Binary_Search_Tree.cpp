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

    void isValidBSTUtils(TreeNode *root, int &prev, bool &result) {
        if(!root or !result) return;
        isValidBSTUtils(root->left, prev, result);
        if(prev >= root->val) {
            result = false;
            return;
        }
        prev = root->val;
        isValidBSTUtils(root->right, prev, result);
    }

    bool isValidBST(TreeNode *root) {
        bool result = true;
        int prev = numeric_limits<int>::min();
        isValidBSTUtils(root, prev, result);
        return result;
    }
};