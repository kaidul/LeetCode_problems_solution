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
    void leafSimilarUtil(TreeNode* root, vector<int>& leafSequence) {
        if(!root) return;
        if(!root->left and !root->right) {
            leafSequence.push_back(root->val);
            return;
        }
        leafSimilarUtil(root->left, leafSequence);
        leafSimilarUtil(root->right, leafSequence);
    }
    
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafSequence1;
        leafSimilarUtil(root1, leafSequence1);
        vector<int> leafSequence2;
        leafSimilarUtil(root2, leafSequence2);
        
        return leafSequence1 == leafSequence2;
    }
};