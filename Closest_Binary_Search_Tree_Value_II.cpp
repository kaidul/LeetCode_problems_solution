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
    void closestKValuesRecur(TreeNode* root, double target, int k, priority_queue<pair<double, int>>& Q) {
         double diff = abs(root->val - target);
         if(Q.size() < k) {
             Q.push(make_pair(diff, root->val));
         } else if(diff < Q.top().first) {
             Q.pop();
             Q.push(make_pair(diff, root->val));
         }
         if(root->left) {
             closestKValuesRecur(root->left, target, k, Q);
         }
         if(root->right) {
             closestKValuesRecur(root->right, target, k, Q);
         }
    }
    
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        priority_queue <pair<double, int>> Q;
        vector<int> result;
        closestKValuesRecur(root, target, k, Q);
        while(!Q.empty()) {
            result.push_back(Q.top().second);
            Q.pop();
        }
        return result;
    }
};