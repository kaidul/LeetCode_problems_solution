/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // O(n^2) (Accepted)
class Solution {
public:
    int maxDepth(TreeNode * root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
     
    bool isBalanced(TreeNode *root) {
        if (!root) return true;
        if (abs(maxDepth(root->left) - maxDepth(root->right)) > 1) return false;
        return (isBalanced(root->left) and isBalanced(root->right));
    }
     
};

// O(n) time and O(Height) space (Accepted) 
class Solution {
public:
    int checkHeight(TreeNode *root) {
        if(!root) {
            return 0;
        }
        int leftHeight = checkHeight(root->left);
        if(leftHeight == -1) {
            return -1;
        } 
        int rightHeight = checkHeight(root->right);
        if(rightHeight == -1) {
            return -1;
        }
        int diff = abs(leftHeight - rightHeight);
        if(diff > 1) {
            return -1;
        } else {
            return max(leftHeight, rightHeight) + 1;
        }
    }
    bool isBalanced(TreeNode *root) {
        if(checkHeight(root) != -1) {
            return true;
        } else {
            return false;
        }
    }
};