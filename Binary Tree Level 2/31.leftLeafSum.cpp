// /404. Sum of Left Leaves

class Solution {
public:
    
    int leftleafSum(TreeNode* root, bool leaf){
        if(root == NULL) return 0;
        
        if(root->left == NULL && root->right == NULL and leaf){
            return root->val;
        }
        
        int ls = leftleafSum(root->left,true);
        int rs = leftleafSum(root->right,false);
        return ls+rs;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        return leftleafSum(root,false);
    }
};