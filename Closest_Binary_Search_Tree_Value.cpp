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
    int closestValue(TreeNode* root, double target) {
        int closest = root->val;
        if(root->val > target and root->left) {
            int leftClosest = closestValue(root->left, target);
            if(abs(target - leftClosest) < abs(target - closest)) {
                closest = leftClosest;
            }
        } else if(root->val < target and root->right) {
            int rightClosest = closestValue(root->right, target);
            if(abs(target - rightClosest) < abs(target - closest)) {
                closest = rightClosest;
            }   
        }
        return closest;
    }
};