// 222. Count Complete Tree Nodes


class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0; 
        
        int lh = findHeightLeft(root); 
        int rh = findHeightRight(root); 
        
        // lh == rh. Means that subtree is Complete SubTree. 1<<lh is 1^lh.
        if(lh == rh) return (1<<lh) - 1; 
        // Add 1 for that Node and Move further on subtree.
        return 1 + countNodes(root->left) + countNodes(root->right); 
    }
    int findHeightLeft(TreeNode* node) {
        int hght = 0; 
        while(node) {
            hght++; 
            node = node->left; 
        }
        return hght; 
    }
    int findHeightRight(TreeNode* node) {
        int hght = 0; 
        while(node) {
            hght++; 
            node = node->right; 
        }
        return hght; 
    }
};