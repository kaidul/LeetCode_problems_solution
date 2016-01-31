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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector <vector <int> > result;
        if(!root) return result;
        int prev_level = 0, curr_level; 
        queue <pair <TreeNode*, int> > Q;
        Q.push(make_pair(root, 1));
        vector <int> container;
        while(!Q.empty()) {
            pair <TreeNode*, int> node = Q.front();
            Q.pop();
            TreeNode *curr_node = node.first;
            curr_level = node.second;
            if(curr_level > prev_level) {
                if(container.size() > 0) 
                    result.push_back(container);
                container.clear();
            }
            
            container.push_back(curr_node->val);
            prev_level = curr_level;
            
            if(curr_node->left) Q.push(make_pair(curr_node->left, curr_level + 1));
            if(curr_node->right) Q.push(make_pair(curr_node->right, curr_level + 1));
        }
        if(container.size() > 0) result.push_back(container);
        return result;
    }
};