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
    void dfs(int start, int end, vector<TreeNode *> &result) {
        if (start > end) {
            result.push_back(NULL);
            return;
        }
        for (int i = start; i <= end; i++) {
            vector<TreeNode *> lefts;
            dfs(start, i - 1, lefts);
            vector<TreeNode *> rights;
            dfs(i + 1, end, rights);

            for (int li = 0; li < lefts.size(); li++) {
                for (int ri = 0; ri < rights.size(); ri++) {
                    TreeNode* node = new TreeNode(i);
                    node->left = lefts[li];
                    node->right = rights[ri];
                    result.push_back(node);
                }
            }
        }
    }

    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode*> res;
        dfs(1, n, res);
        return res;
    }
};