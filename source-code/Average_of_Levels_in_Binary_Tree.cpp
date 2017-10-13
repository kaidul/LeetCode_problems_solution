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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if(!root) {
            return result;
        }
        unordered_map<int, long long> sum;
        unordered_map<int, int> nodeCount;
        queue<pair<TreeNode*, int>> Q;
        int level = 0;
        Q.push({root, level});
        while(!Q.empty()) {
            TreeNode* curr = Q.front().first;
            int currLevel = Q.front().second;
            Q.pop();
            if(currLevel > level) {
                double avg = (double) sum[level] / nodeCount[level];
                result.push_back(avg);
                level = currLevel;
            }
            sum[level] += curr->val;
            nodeCount[level]++;
            if(curr->left) {
               Q.push({curr->left, currLevel + 1}); 
            }
            if(curr->right) {
               Q.push({curr->right, currLevel + 1}); 
            }
        }
        double avg = (double) sum[level] / nodeCount[level];
        result.push_back(avg);

        return result;
    }
};