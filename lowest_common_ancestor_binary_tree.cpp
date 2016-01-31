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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;

        if(root == p or root == q) {
            return root;
        }
        TreeNode* leftLca = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLca = lowestCommonAncestor(root->right, p, q);
        
        if(leftLca and rightLca) {
            return root;
        }
        
        return (leftLca) ? leftLca : rightLca;
    }
};