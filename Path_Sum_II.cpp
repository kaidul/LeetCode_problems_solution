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
    void build(TreeNode *root, vector<vector<int> > &res, vector<int> &sol, int sum, int s) {
      if(!root->left and !root->right and (s + root->val) == sum) {
          sol.push_back(root->val);
          res.push_back(sol);
          sol.pop_back();
          return;
      }
      
      s += root->val;
      sol.push_back(root->val);
      
      if(root->left) build(root->left, res, sol, sum, s);
      if(root->right) build(root->right, res, sol, sum, s);
      
      sol.pop_back();
    }
    
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        if(!root) return res;
        
        vector<int> sol;
        build(root, res, sol, sum, 0);
        
        return res;
        
        
    }
};