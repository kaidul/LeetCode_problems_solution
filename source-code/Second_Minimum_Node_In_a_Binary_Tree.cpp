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
    void findSecondMinimumValue(TreeNode* root, const int minimum, int& secondMinimum) {
        if(!root) return;
        
        if(root->val > minimum) {
            secondMinimum = (secondMinimum != -1) ? min(secondMinimum, root->val) : root->val;
        }
        
        if(root->right != nullptr and root->right->val > root->val) {
            secondMinimum = (secondMinimum != -1) ? min(secondMinimum, root->right->val) : root->right->val;
        } else {
            findSecondMinimumValue(root->right, minimum, secondMinimum);    
        }
        
        findSecondMinimumValue(root->left, minimum, secondMinimum);
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        int secondMinimum = -1;
        findSecondMinimumValue(root, root->val, secondMinimum);
        return secondMinimum;
    }
};