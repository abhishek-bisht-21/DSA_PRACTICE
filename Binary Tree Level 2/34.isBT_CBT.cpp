// 958. Check Completeness of a Binary Tree

class Solution {
public:
    
    bool isCBT(TreeNode* root, int i, int node_Count){
        if(root == NULL){
            return true;
        }
        
        if(i >= node_Count){
            return false;
        }
        
        else{
            bool left = isCBT(root->left,2*i+1,node_Count);
            bool right = isCBT(root->right,2*i+2,node_Count);
            
            return (left && right);
        }
    }
    
    int nodeCount(TreeNode* root){
        
        if(root == NULL){
            return 0;
        }
        
        int lCount = nodeCount(root->left);
        int rCount = nodeCount(root->right);
        
        return lCount + rCount + 1;
    }
    
    bool isCompleteTree(TreeNode* root) {
        
        int node_Count = nodeCount(root);
        return isCBT(root,0,node_Count);
    }
};