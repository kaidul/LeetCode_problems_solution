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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map <int, vector<int>> verticalMap;
        vector<vector<int>> result;
        if(!root) {
            return result;
        }
        queue < pair<TreeNode*, int> > Q;
        Q.push(make_pair(root, 0));
        while(!Q.empty()) {
            TreeNode* node = Q.front().first;
            int indx = Q.front().second;
            Q.pop();
            verticalMap[indx].push_back(node->val);
            if(node->left) {
                Q.push(make_pair(node->left, indx - 1));
            }
            if(node->right) {
                Q.push(make_pair(node->right, indx + 1));
            }
        }
        for(auto it = verticalMap.begin(); it != verticalMap.end(); ++it) {
            result.push_back(it->second);
        }
        return result;
    }
};