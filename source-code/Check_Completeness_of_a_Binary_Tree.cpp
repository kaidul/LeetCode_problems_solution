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
    bool isLevelComplete(int level, vector<int>& currLevelNodes) {
        return (int)currLevelNodes.size() == (1 << level);
    }
    
    bool firstNodeIsLeftMost(int level, vector<int>& currLevelNodes) {
        if (currLevelNodes.empty()) {
            return true;
        }
        return currLevelNodes[0] == (1 << level);
    }
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) {
            return true;
        }
        int level = 0;
        queue<pair<TreeNode*, pair<int, int>>> Q;
        Q.push({root, {level, 1}});
        vector<int> currLevelNodes;
        currLevelNodes.push_back(1);
        
        while (!Q.empty()) {
            pair<TreeNode*, pair<int, int>> curr = Q.front();
            TreeNode* currNode = curr.first;
            int currLevel = curr.second.first;
            int nodeSeq = curr.second.second;
            Q.pop();
            if (level == 0 or currLevel > level) {
                if (!isLevelComplete(level, currLevelNodes)) {
                    return false;
                }
                currLevelNodes = vector<int>();
                level = currLevel;
            }
            currLevelNodes.push_back(nodeSeq);
            if (currNode->left) {
                Q.push({currNode->left, {currLevel + 1, nodeSeq << 1}});
            }
            if (currNode->right) {
                Q.push({currNode->right, {currLevel + 1, (nodeSeq << 1) | 1}});
            }
        }
        
        // last level
        if (!isLevelComplete(level, currLevelNodes)) {
            if (!firstNodeIsLeftMost(level, currLevelNodes)) {
                return false;
            }
            for(int i = 0; i < (int)currLevelNodes.size() - 1; i++) {
                if (currLevelNodes[i + 1] != currLevelNodes[i] + 1) {
                    return false;
                }
            }
        } 
        return true;
    }
};