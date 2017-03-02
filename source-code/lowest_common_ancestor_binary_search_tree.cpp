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
    unordered_map <TreeNode*, TreeNode*> parent;
    unordered_map <TreeNode*, int> depth;
    unordered_map <TreeNode*, unordered_map<int, TreeNode*> > lcaTable;

    void bfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue <TreeNode*> Q;
        Q.push(root);
        parent[root] = root;
        depth[root] = 0;
        lcaTable[root][0] = root;
        bool foundP = false, foundQ = false;
        while(!Q.empty()) {
            TreeNode* node = Q.front();
            Q.pop();
            TreeNode* left = node->left;
            TreeNode* right = node->right;
            if(left) {
                if(left->val == p->val) {
                    foundP = true;
                } else if(left->val == q->val) {
                    foundQ = true;
                }
                lcaTable[left][0] = node;
                depth[left] = depth[node] + 1;
                parent[left] = node;
                Q.push(left);
            }
            if(right) {
                if(right->val == p->val) {
                    foundP = true;
                } else if(right->val == q->val) {
                    foundQ = true;
                }
                lcaTable[right][0] = node;
                depth[right] = depth[node] + 1;
                parent[right] = node;
                Q.push(right);
            }
            if(foundP and foundQ) {
                break;
            }
        }
    }

    void lcaInit(TreeNode* p) {
        for(int i = 1; (1 << i) < depth[p]; ++i) {
            lcaTable[p][i] = lcaTable[lcaTable[p][i - 1]][i - 1];
        }
    }

    int logDepth(TreeNode* p) {
        int log = 1;
        while(true) {
            int next = log + 1;
            if((1 << next) > depth[p]) break;
            log++;
        }
        return log;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        /*
        // RTE :(
        bfs(root, p, q);
        lcaInit(p);
        lcaInit(q);

        if(depth[p] < depth[q]) swap(p, q);

        int log = logDepth(p);

        for(int i = log - 1; i >= 0; --i) {
            if(depth[p] - (1 << i) >= depth[q]) {
                p = lcaTable[p][i];
            }
        }

        if(p->val == q->val) return p;

        log = logDepth(p);
        for(int i = log - 1; i >= 0; --i) {
            if(lcaTable[p][i] != lcaTable[q][i]) {
                p = lcaTable[p][i], q = lcaTable[q][i];
            }
        }
        return parent[p];
        */
        if(root->val > p->val and root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if(root->val < p->val and root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};