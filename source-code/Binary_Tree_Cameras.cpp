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
    const int HAS_NO_CAMERA_AND_NOT_MONITORED = 0;
    const int HAS_NO_CAMERA_BUT_MONITORED = 1;
    const int HAS_CAMERA = 2;
    
    int minCameraCover(TreeNode* root, int& totalCameras) {
        if (!root) {
            return HAS_NO_CAMERA_BUT_MONITORED;
        }
        int left = minCameraCover(root->left, totalCameras);
        int right = minCameraCover(root->right, totalCameras);
        
        if (left == HAS_NO_CAMERA_AND_NOT_MONITORED or 
            right == HAS_NO_CAMERA_AND_NOT_MONITORED) {
            
            totalCameras++;
            return HAS_CAMERA;
        }
        else if (left == HAS_CAMERA or 
                 right == HAS_CAMERA) {
            
            return HAS_NO_CAMERA_BUT_MONITORED;
        }
        
        return HAS_NO_CAMERA_AND_NOT_MONITORED;
    }
public:
    int minCameraCover(TreeNode* root) {
        int totalCameras = 0;
        if (minCameraCover(root, totalCameras) == HAS_NO_CAMERA_AND_NOT_MONITORED) {
            totalCameras++;
        }
        return totalCameras;    
    }
};