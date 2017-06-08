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
    string tree2strUtil(TreeNode* root) {
        if(!root) { return "()"; }
        string path = "(";
        path += to_string(root->val);
        if(root->left) {
            path += tree2strUtil(root->left);
        }
        if(root->right) {
           if(!root->left) {
               path += tree2strUtil(root->left);
           }
           path += tree2strUtil(root->right);
        }
        path += ")";
        
        return path;
    }
public:
    string tree2str(TreeNode* root) {
        string result = tree2strUtil(root);
        return result.substr(1, result.length() - 2);
    }
};