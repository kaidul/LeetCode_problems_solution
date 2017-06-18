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
    void addOneRow(TreeNode* curr, int depth, const int v, const int d) {
        if(depth == d - 1) {
            TreeNode* left = curr->left;
            curr->left = new TreeNode(v);
            curr->left->left = left;
            TreeNode* right = curr->right;
            curr->right = new TreeNode(v);
            curr->right->right = right;
            return;
        }
        if(curr->left) addOneRow(curr->left, depth + 1, v, d);
        if(curr->right) addOneRow(curr->right, depth + 1, v, d);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1) {
            TreeNode* newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        addOneRow(root, 1, v, d);
        return root;
    }
};