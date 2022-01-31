// 124. Binary Tree Maximum Path Sum

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathSumDown(root,maxi);
        return maxi;
    }
    
    int maxPathSumDown(TreeNode* root, int &maxi){
        if(root == nullptr) return 0;
        
        int lsum = max(0,maxPathSumDown(root->left,maxi));
        int rsum = max(0,maxPathSumDown(root->right,maxi));
        maxi = max(maxi,lsum+rsum+root->val);
        return max(lsum,rsum) + root->val;
        
    }
};