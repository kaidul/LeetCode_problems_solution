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
    void traverse(TreeNode* node, unordered_map <TreeNode*, unordered_set<TreeNode*> >& adj, queue<TreeNode*>& leaves) {
        if(!node) return;
        if(!node->left and !node->right) {
            leaves.push(node);
            return;
        }
        if(node->left) {
            adj[node].insert(node->left);
            adj[node->left].insert(node);
            traverse(node->left, adj, leaves);
        }
        if(node->right) {
            adj[node].insert(node->right);
            adj[node->right].insert(node);
            traverse(node->right, adj, leaves);
        }
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        unordered_map <TreeNode*, unordered_set<TreeNode*> > adj;
        queue<TreeNode*> leaves;
        traverse(root, adj, leaves);
        while(!leaves.empty()) {
            int k = (int)leaves.size();
            vector<int> currLeaves;
            while(k--) {
                TreeNode* curr = leaves.front();
                currLeaves.push_back(curr->val);
                for(auto neigh = adj[curr].begin(); neigh != adj[curr].end(); ++neigh) {
                    adj[*neigh].erase(curr);
                    if((*neigh == root and adj[*neigh].empty()) or (*neigh != root and adj[*neigh].size() == 1)) {
                        leaves.push(*neigh);
                    }
                }
                adj[curr].clear();
                leaves.pop();
            }
            result.push_back(currLeaves);
        }
        
        return result;
    }
};