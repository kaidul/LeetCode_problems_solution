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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, pair<int, int>>> Q;
        int level = -1;
        int maxWidth = 0;
        int minIndx = 1, maxIndx = 1;
        Q.push({root, {0, 1}});
        while(!Q.empty()) {
            TreeNode* curr = Q.front().first;
            int currLevel = Q.front().second.first;
            int currIndx = Q.front().second.second;
            Q.pop();
            if(currLevel != level) {
                level = currLevel;
                maxWidth = max(maxWidth, maxIndx - minIndx + 1);
                minIndx = currIndx;
            }
            maxIndx = currIndx;
            if(curr->left) {
                Q.push({curr->left, {currLevel + 1, currIndx << 1}});
            }
            if(curr->right) {
                Q.push({curr->right, {currLevel + 1, ((currIndx << 1) | 1)}});
            }
        }
        maxWidth = max(maxWidth, maxIndx - minIndx + 1);
        return maxWidth;
    }
};