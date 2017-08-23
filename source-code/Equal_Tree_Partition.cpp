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
    int accumulate(TreeNode* root) {
        if(!root) { return 0; }
        return root->val += accumulate(root->left) + accumulate(root->right); 
    }
    
    bool checkEqualTree(TreeNode* node, int const sum) {
        if(!node) return false;
        if(sum - node->val == node->val or checkEqualTree(node->left, sum) or checkEqualTree(node->right, sum)) {
            return true;
        }
        return false;
    }
public:
    bool checkEqualTree(TreeNode* root) {
        int total = accumulate(root);
        return checkEqualTree(root->left, total) or checkEqualTree(root->right, total);
    }
};