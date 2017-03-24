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
    TreeNode* str2tree(string s) {
        stack<TreeNode*> nodeStack;
        int n = (int)s.length();
        if(n == 0) return nullptr;
        int i = 0;
        while(i < n) {
            if(isdigit(s[i]) or s[i] == '-') {
                bool positive = true;
                if(s[i] == '-') {
                    positive = false;
                    i++;
                }
                int value = s[i] - '0';
                while(i + 1 < n and isdigit(s[i + 1])) {
                    value = value * 10 + (s[i + 1] - '0');
                    i++;
                }
                if(!positive) {
                    value = -value;
                }
                TreeNode* node = new TreeNode(value);
                if(!nodeStack.empty()) {
                    TreeNode* parent = nodeStack.top();
                    if(!parent->left) {
                        parent->left = node;
                    } else {
                        parent->right = node;
                    }
                }
                nodeStack.push(node);
            }
            else if(s[i] == ')') {
                nodeStack.pop();
            }
            else if(s[i] == '(') {
                // nothing    
            }
            i++;
        }
        return nodeStack.top();
    }
};