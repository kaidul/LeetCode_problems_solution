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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> result;
        if(!root) return result;
        queue< pair<TreeNode*, int> > Q;
        int curr = root->val;
        int currLevel = 1;
        Q.push(make_pair(root, 1));
        while(!Q.empty()) {
            TreeNode* node = Q.front().first;
            int level = Q.front().second;
            if(level > currLevel) {
                result.push_back(curr);
                currLevel = level;
            }
            curr = node->val;
            Q.pop();
            if(node->left) Q.push(make_pair(node->left, level + 1));
            if(node->right) Q.push(make_pair(node->right, level + 1));
        }
        result.push_back(curr);
        return result;
    }
};