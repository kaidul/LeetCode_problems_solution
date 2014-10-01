/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        queue <pair <TreeLinkNode*, int> > Q;
        int prev_level = 0, curr_level;
        Q.push(make_pair(root, 1));
        pair <TreeLinkNode*, int> node;
        TreeLinkNode *curr = nullptr, *head = nullptr;
        while(!Q.empty()) {
            node = Q.front(), Q.pop();
            curr_level = node.second, curr = node.first;
            
            if(curr_level > prev_level) {
                if(head) head->next = nullptr;
                head = curr;
            } else {
                head->next = curr;
                head = head->next;
            }
            
            if(curr->left) Q.push(make_pair(curr->left, curr_level + 1));
            if(curr->right) Q.push(make_pair(curr->right, curr_level + 1));
            
            prev_level = curr_level;
        }
     }
};