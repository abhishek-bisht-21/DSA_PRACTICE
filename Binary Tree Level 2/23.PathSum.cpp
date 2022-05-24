// 112. Path Sum


class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root == nullptr) return false;
        
        if(root->left == nullptr and root->right == nullptr){
            return (targetSum - root->val) == 0;
        }
        
        return hasPathSum(root->left,targetSum-root->val) || hasPathSum(root->right,targetSum-root->val);
        
    }
};