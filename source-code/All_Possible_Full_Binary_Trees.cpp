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
    vector<TreeNode*> allPossibleFBT(int n, vector<TreeNode*>& result) {
        if(n == 0) {
            result.push_back(nullptr);
            return result;
        }
        if(n % 2 == 0) {
            return vector<TreeNode*>();
        }
        for(int i = 1; i <= n; i++) {
            int leftTreeNodeCount = i - 1;
            int rightTreeNodeCount = n - i;
            
            vector<TreeNode*> leftSubTrees;
            allPossibleFBT(leftTreeNodeCount, leftSubTrees);
            
            vector<TreeNode*> rightSubTrees;
            allPossibleFBT(rightTreeNodeCount, rightSubTrees);
            
            for(TreeNode* leftSubTree : leftSubTrees) {
                for(TreeNode* rightSubTree : rightSubTrees) {
                    TreeNode* root = new TreeNode(0);
                    root->left = leftSubTree;
                    root->right = rightSubTree;
            
                    result.push_back(root);
                }
            }
            
        }
        return result;
    }
    
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> result;
        allPossibleFBT(N, result);
        return result;
    }
};