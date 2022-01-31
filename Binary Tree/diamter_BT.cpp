class Solution {
public:
    
    
    int diameterOfBinaryTree_helper(TreeNode* root, int &dia) {
        
        if(root == nullptr){
            return 0;
        }
        
        int lht = diameterOfBinaryTree_helper(root->left,dia);
        int rht = diameterOfBinaryTree_helper(root->right,dia);
        
       
        
        dia = max(lht+rht,dia);
        int height = max(lht,rht) + 1;
        
        return height;
    }
    
    int diameterOfBinaryTree(TreeNode* root){
        int dia = 0;
        diameterOfBinaryTree_helper(root,dia);
        return dia;
    }
};