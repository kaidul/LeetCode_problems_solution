/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// with single DFS(like diameter of a tree)
class Solution {
    int longestUnivaluePath(TreeNode* root, int& longestPath) {
        if(!root) return 0;
        int leftDepth = longestUnivaluePath(root->left, longestPath);
        int rightDepth = longestUnivaluePath(root->right, longestPath);
        
        if(root->left and root->left->val == root->val) {
            leftDepth++;
        } else {
            leftDepth = 0;
        }
        
        if(root->right and root->right->val == root->val) {
            rightDepth++;
        } else {
            rightDepth = 0;
        }
        
        longestPath = max(longestPath, leftDepth + rightDepth);
        
        return max(leftDepth, rightDepth);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        int longestPath = 0;
        longestUnivaluePath(root, longestPath);
        
        return longestPath;
    }
};

// O(n^2)
class Solution {
    int longestUnivaluePath(TreeNode* root, int val) {
        if(!root or root->val != val) return 0;
        return 1 + max(longestUnivaluePath(root->left, val), longestUnivaluePath(root->right, val));
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        int sub = max(longestUnivaluePath(root->left), longestUnivaluePath(root->right));
        return max(sub, longestUnivaluePath(root->left, root->val) + longestUnivaluePath(root->right, root->val));
    }
};