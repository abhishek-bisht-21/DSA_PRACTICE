// 226. Invert Binary Tree

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        
        TreeNode* leftSub = invertTree(root->right);
        TreeNode* rightSub = invertTree(root->left);
        
        root->left = leftSub;
        root->right = rightSub;
        
        return root;
    }
};