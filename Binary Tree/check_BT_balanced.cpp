
// 110. Balanced Binary Tree
class Solution {
public:
    
    int isBalanced_helper(TreeNode* root, bool &isbal){
        if(root == nullptr) return 0;
        
        int lh =isBalanced_helper(root->left,isbal);
        int rh = isBalanced_helper(root->right,isbal);
        
       int ht = max(lh,rh)+1;
    
        int gap = abs(lh - rh);
        if(gap > 1){
            isbal = false;
        }
    
         return ht;
    }
    
    bool isBalanced(TreeNode* root) {
        
        bool isbal = true;
        isBalanced_helper(root,isbal);
        return isbal;
    }
};