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
    int maxHeight(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(maxHeight(root->left), maxHeight(root->right));
    }
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector < vector<int> > result;
        if(!root) return result;
        int height = maxHeight(root);
        result.resize(height);
        queue < pair <TreeNode*, int> > Q;
        int prev_level = 0, curr_level;
        Q.push(make_pair(root, 1));
        vector <int> container;
        while(!Q.empty()) {
            pair <TreeNode*, int> node = Q.front();
            Q.pop();
            TreeNode *curr = node.first;
            curr_level = node.second;
            if(curr_level > prev_level) {
                if(container.size() > 0) {
                    result[--height] = container;
                }
                container.clear();
            }
            container.push_back(curr->val);
            
            if(curr->left) Q.push(make_pair(curr->left, curr_level + 1));
            if(curr->right) Q.push(make_pair(curr->right, curr_level + 1));
            
            prev_level = curr_level;
        }
        if(container.size() > 0) result[--height] = container;
        
        return result;
    }
};