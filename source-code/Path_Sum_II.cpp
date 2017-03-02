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
    void build(TreeNode *root, vector<vector<int> > &result, vector<int> &solution, int sum) {
        if(!root) return;
        if(!root->left and !root->right) {
          if(root->val == sum) {
            solution.push_back(root->val);
            result.push_back(solution);
            solution.pop_back();
          }
          return;
        }
        
        solution.push_back(root->val);
        if(root->left) build(root->left, result, solution, sum - root->val);
        if(root->right) build(root->right, result, solution, sum - root->val);
        solution.pop_back();
    }
    
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        if(!root) return res;
        
        vector<int> sol;
        build(root, res, sol, sum);
        
        return res;
        
        
    }
};