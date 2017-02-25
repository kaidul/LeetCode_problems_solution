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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if(!root) return result;
        queue<pair<TreeNode*, int>> Q;
        int currLevel = 0;
        Q.push({root, currLevel});
        int maxElem = root->val;
        while(!Q.empty()) {
            TreeNode* node = Q.front().first;
            int value = node->val;
            int level = Q.front().second;
            if(level > currLevel) {
                result.push_back(maxElem);
                currLevel = level;
                maxElem = value;
            } else {
                maxElem = max(maxElem, value);
            }
            Q.pop();
            if(node->left) {
                Q.push({node->left, level + 1});
            }
            if(node->right) {
                Q.push({node->right, level + 1});    
            }
        }
        result.push_back(maxElem);
        
        return result;
    }
};