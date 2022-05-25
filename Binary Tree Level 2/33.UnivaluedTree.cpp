// /965. Univalued Binary Tree

class Solution {
public:
    
    void preOrder(TreeNode* root,int val,bool &ans)
    {
        if(root == NULL){
            return;
        }
        
        if(root->val != val){
            ans = false;
            return;
        }
        
        preOrder(root->left,val,ans);
        preOrder(root->right,val,ans);
    }
    bool isUnivalTree(TreeNode* root) {
         bool ans = true;   
         preOrder(root,root->val,ans);
         return ans;
    }
};