// 113. Path Sum II

class Solution {
public:
    
    void pathSumHelper(TreeNode* root,int targetSum,vector<int> &temp,vector<vector<int>> &ans){
        
        if(root == nullptr) return;
        
        if(root->left == nullptr and root->right == nullptr){
            if(targetSum - root->val == 0){
                temp.push_back(root->val);
                ans.push_back(temp);
                temp.pop_back();
            }
            
            return;
        }
        
        temp.push_back(root->val);
        pathSumHelper(root->left,targetSum-root->val,temp,ans);
        pathSumHelper(root->right,targetSum-root->val,temp,ans);
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<int> temp;
        vector<vector<int>> ans;
        
        pathSumHelper(root,targetSum,temp,ans);
        return ans;
    }
};