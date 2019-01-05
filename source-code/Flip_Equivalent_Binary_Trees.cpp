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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 and !root2) {
            return true;
        }
        if (!root1 or !root2) {
            return false;
        }
        return root1->val == root2->val 
            and (
            (flipEquiv(root1->left, root2->left) and flipEquiv(root1->right, root2->right)) 
            or (flipEquiv(root1->left, root2->right) and flipEquiv(root1->right, root2->left))
        );
    }
};