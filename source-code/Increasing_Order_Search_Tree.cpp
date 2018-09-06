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
    void increasingBSTRecur(TreeNode* root, TreeNode*& parent, TreeNode*& newRoot) {
        if(!root) return;
        
        increasingBSTRecur(root->left, parent, newRoot);
        
        if(!newRoot) {
            newRoot = root;
        }
        root->left = nullptr;
        if(parent) parent->right = root;
        parent = root;
        
        increasingBSTRecur(root->right, parent, newRoot);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* newRoot = nullptr;
        TreeNode* parent = nullptr;
        increasingBSTRecur(root, parent, newRoot);
        
        return newRoot;
    }
};