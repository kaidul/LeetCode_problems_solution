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
    int findBottomLeftValue(TreeNode* root) {
        queue<pair<TreeNode*, int>> Q;
        int currLevel = 1;
        Q.push({root, currLevel});
        int leftMost = root->val;
        while(!Q.empty()) {
            TreeNode* node = Q.front().first;
            int level = Q.front().second;
            Q.pop();
            if(level > currLevel) {
                leftMost = node->val;
                currLevel = level;
            }
            if(node->left) {
                Q.push({node->left, level + 1});
            }
            if(node->right) {
                Q.push({node->right, level + 1});
            }
        }
        return leftMost;
    }
};