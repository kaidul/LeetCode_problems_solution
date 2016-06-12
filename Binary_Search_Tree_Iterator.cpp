/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    vector<int> nodes;
    vector<int>::iterator iter;
    
    void BSTIteratorUtils(TreeNode *node) {
        if(!node) return;
        BSTIteratorUtils(node->left);
        nodes.push_back(node->val);
        BSTIteratorUtils(node->right);
    }
    
public:
    BSTIterator(TreeNode *root) {
        nodes = vector<int>();
        BSTIteratorUtils(root);
        iter = nodes.begin();
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return iter != nodes.end();
    }

    /** @return the next smallest number */
    int next() {
        return (*iter++);
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */