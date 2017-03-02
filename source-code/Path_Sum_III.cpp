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
    int pathSumUtil(TreeNode* root, int curr, const int sum, unordered_map<int, int>& sumMap) {
        if(!root) return 0;
        curr += root->val;
        int freq = sumMap[curr - sum];
        sumMap[curr]++;
        int ret = freq + pathSumUtil(root->left, curr, sum, sumMap) + pathSumUtil(root->right, curr, sum, sumMap);
        sumMap[curr]--;
        return ret;
    }
    
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> sumMap;
        sumMap[0]++;
        return pathSumUtil(root, 0, sum, sumMap);
    }
};