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
    void generateTreesUtil(int left, int right, vector<TreeNode*>& result) {
        if(left > right) {
            result.push_back(nullptr);
            return;
        }
        for(int i = left; i <= right; i++) {
            vector<TreeNode*> leftSubTrees;
            generateTreesUtil(left, i - 1, leftSubTrees);
            vector<TreeNode*> rightSubTrees;
            generateTreesUtil(i + 1, right, rightSubTrees);
            
            for(TreeNode* leftSubTree : leftSubTrees) {
                for(TreeNode* rightSubTree : rightSubTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftSubTree;
                    root->right = rightSubTree;
                    result.push_back(root);
                }    
            }
        }
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        if(n == 0) return result;
        generateTreesUtil(1, n, result);
        return result;
    }
};
