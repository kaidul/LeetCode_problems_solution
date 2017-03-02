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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* curr = root;
        while(curr) {
            if(!curr->left) {
                TreeNode* parent = curr;
                curr = curr->right;
                if(parent == p) {
                    while(curr and curr->left) {
                        curr = curr->left;
                    }
                    return curr;
                }
            } else {
                TreeNode* leftNode = curr->left;
                TreeNode* rightMost = leftNode;
                while(rightMost->right) {
                    rightMost = rightMost->right;
                }
                rightMost->right = curr;
                curr->left = nullptr;
                curr = leftNode;
            }
        }
        return root;
    }
};