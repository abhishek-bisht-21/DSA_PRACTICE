// 968. Binary Tree Cameras

// Traverse the tree in post order
// IF YOU NEED A CAMERA: -1
// YOU HAVE CAMERA : 0
// IF YOU ARE COVERED : 1

// At every node we have to decide whether that node needs a camera or not.
// Those who do not need camera, either they are already covered or needs covering.

class Solution {
public:
    
    int camera = 0;
    
    int minCameraCover_(TreeNode* root) {
        if(root == NULL) return 1;
        
        int lchild = minCameraCover_(root->left);
        int rchild = minCameraCover_(root->right);
        
        if(lchild == -1 or rchild == -1){
            camera++;
            return 0;
        }
        
        if(lchild == 0 or rchild == 0) return 1;
        
        return -1;
    }
    
    
    int minCameraCover(TreeNode* root) {
        if(minCameraCover_(root) == -1) camera++;
        return camera;
    }
};