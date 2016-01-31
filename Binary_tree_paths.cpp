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
    void binaryTreePathsUtil(TreeNode* root, string path, vector<string>& result) {
        if(!root) return;
        if(!root->left and !root->right) {
            result.push_back(path + to_string(root->val));
            return;
        }
        if(root->left) binaryTreePathsUtil(root->left, path + to_string(root->val) + "->", result);    
        if(root->right) binaryTreePathsUtil(root->right, path + to_string(root->val) + "->", result);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        binaryTreePathsUtil(root, "", result);
        return result;
    }
};