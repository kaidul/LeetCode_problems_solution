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
    int calculateMaxHeight(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(calculateMaxHeight(root->left), calculateMaxHeight(root->right));
    }
    
    int calculateScore(TreeNode* root, unordered_map<TreeNode*, int>& score, int& maxScore, int currHeight, int maxHeight) {
        if(!root) return 0;
        score[root] = 
            (currHeight == maxHeight) 
            + calculateScore(root->left, score, maxScore, currHeight + 1, maxHeight)
            + calculateScore(root->right, score, maxScore, currHeight + 1, maxHeight);
        
        maxScore = max(maxScore, score[root]);
        
        return score[root];
    }
    
    void rootOfSubTreeWithAllDeepestNodes(TreeNode* root, unordered_map<TreeNode*, int>& score, int currDepth, TreeNode*& result, int& maxDepth, int maxScore) {
        if(!root) return;
        if(score[root] < maxScore) {
            return;
        }
        if(score[root] == maxScore) {
            if(currDepth > maxDepth) {
                maxDepth = currDepth;
                result = root;
            }
        }
        rootOfSubTreeWithAllDeepestNodes(root->left, score, currDepth + 1, result, maxDepth, maxScore);
        rootOfSubTreeWithAllDeepestNodes(root->right, score, currDepth + 1, result, maxDepth, maxScore);
    }
    
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root) return root;
        int maxHeight = calculateMaxHeight(root);
        
        unordered_map<TreeNode*, int> score;
        int maxScore = 0;
        calculateScore(root, score, maxScore, 1, maxHeight);
        
        TreeNode* result = root;
        int maxDepth = 1;
        rootOfSubTreeWithAllDeepestNodes(root, score, 1, result, maxDepth, maxScore);
        
        return result;
    }
};