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
    void flatten(TreeNode* root) {
        while(root) {
            if(root->left) {
                TreeNode* right = root->right;
                root->right = root->left;
                root->left = nullptr;
                TreeNode* left = root->right; 
                while(left->right) {
                    left = left->right;
                } 
                left->right = right;
            }
            root = root->right;
        }
    }
};
