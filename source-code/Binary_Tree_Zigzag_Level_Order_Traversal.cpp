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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector <vector <int> > result;
        if(!root) return result;
        queue < pair <TreeNode*, int> > Q;
        int prev_level = 0, curr_level;
        vector <int> container;
        Q.push(make_pair(root, 1));
        int zigzag = 0;
        while(!Q.empty()) {
            pair<TreeNode*, int> node = Q.front();
            Q.pop();
            TreeNode *curr = node.first;
            curr_level = node.second;
            
            if(curr_level > prev_level) {
                if(container.size() > 0) {
                    if(zigzag) reverse(container.begin(), container.end());
                    result.push_back(container);
                    zigzag ^= 1;
                }
                container.clear();
            }
            container.push_back(curr->val);
        
            if(curr->left) Q.push(make_pair(curr->left, curr_level + 1));
            if(curr->right) Q.push(make_pair(curr->right, curr_level + 1));
            
            prev_level = curr_level;
        }
        if(container.size() > 0) {
            if(zigzag) reverse(container.begin(), container.end());
            result.push_back(container);
        }
        return result;
    }
};