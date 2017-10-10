/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// AC
// postorder and preorder signature will work, inorder not.
class Solution {
    string preorder(TreeNode* root, unordered_map<string, int>& preOrderMap, vector<TreeNode*>& result) {
        if(!root) {
            return "#";
        }
        signature += "," + to_string(root->val);
        string signature = preorder(root->left, preOrderMap, result);
        signature += "," + preorder(root->right, preOrderMap, result);
        // signature += "," + to_string(root->val); would work too
        
        if(preOrderMap[signature] == 1) {
            result.push_back(root);
        }
        preOrderMap[signature]++;
        return signature;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result;
        unordered_map<string, int> preOrderMap;
        preorder(root, preOrderMap, result);
        return result;
    }
};

// brute-force, TLE, 121/167 testcases passed
class Solution {
    bool isSame(TreeNode* rootA, TreeNode* rootB) {
        if(!rootA and !rootB) {
            return true;
        }
        if(!rootA or !rootB) {
            return false;
        }
        return rootA->val == rootB->val and isSame(rootA->left, rootB->left) and isSame(rootA->right, rootB->right);
    }
    
    bool hasDuplicate(TreeNode* node, TreeNode* root, unordered_set<TreeNode*>& visited) {
        if(!root) {
            return false;
        }
        if(visited.find(root) == visited.end() and isSame(node, root)) {
            visited.insert(root);
            return true;
        }
        int leftDuplicate = hasDuplicate(node, root->left, visited);
        int rightDuplicate = hasDuplicate(node, root->right, visited);
        
        return leftDuplicate or rightDuplicate;
    }
    
    void findDuplicateSubtrees(TreeNode* node, TreeNode* root, vector<TreeNode*>& result, unordered_set<TreeNode*>& visited) {
        if(!node) {
            return;
        }
        if(visited.find(node) == visited.end()) {
            visited.insert(node);
            if(hasDuplicate(node, root, visited)) {
                result.push_back(node);
            }
        }
        
        findDuplicateSubtrees(node->left, root, result, visited);
        findDuplicateSubtrees(node->right, root, result, visited);
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_set<TreeNode*> visited;
        vector<TreeNode*> result;
        findDuplicateSubtrees(root, root, result, visited);
        return result;
    }
};