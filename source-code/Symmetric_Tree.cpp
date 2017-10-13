/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// using level order traversal
class Solution {
public:
    bool isPalindrome(vector<int> &container) {
        for(int i = 0, j = container.size() - 1; i < j; ++i, --j) {
            if(container[i] != container[j])
                return false;
        }
        return true;
    }    
        
    bool isSymmetric(TreeNode *root) {
        if(root == NULL) return true;
        queue < pair<TreeNode*, int> > q;
        q.push(make_pair(root, 1));
        int prev_level = 0, curr_level;
        pair<TreeNode*, int> node;
        TreeNode *dummy = new TreeNode(-(1 << 30)), *curr;
        vector <int> container;
        
        while(!q.empty()) {
            
            node = q.front(), q.pop();
            curr = node.first;
            curr_level = node.second;
            
            if(curr_level > prev_level) {
                if(!isPalindrome(container))
                    return false;
                container.clear();
            }
            
            container.push_back(curr->val);
            prev_level = curr_level;
            
            if(curr->val == dummy->val) continue;
            
            if(curr->left) q.push(make_pair(curr->left, curr_level + 1));
            else q.push(make_pair(dummy, curr_level + 1));
            
            if(curr->right) q.push(make_pair(curr->right, curr_level + 1));
            else q.push(make_pair(dummy, curr_level + 1));
        }
        return true;
    }
};

// using recursion
class Solution {
    bool isSymmetric(TreeNode* root1, TreeNode* root2) {
        if(!root1 and !root2) {
            return true;
        }
        if(!root1 or !root2) {
            return false;
        }
        return root1->val == root2->val and isSymmetric(root1->left, root2->right) and isSymmetric(root1->right, root2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }
};