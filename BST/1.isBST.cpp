
// Approach 1 -> Inorder of a BST is Sorted
class Solution {
public:
    
    void inOrder(TreeNode* root,vector<TreeNode*> &ans){
        
        if(root == nullptr){
            return;
        }
        
        inOrder(root->left,ans);
        ans.push_back(root);
        inOrder(root->right,ans);
        
        
    }
    
    bool isValidBST(TreeNode* root) {
        
        vector<TreeNode*> ans;
        inOrder(root,ans);
        
        int prev = 0;
        for(int i=1;i<ans.size();i++){
            if(ans[prev++]->val >= ans[i]->val){
                return false;
            }
        }
        
        return true;
    }
};


// Approach 2 
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return isValidBST(root,prev);
    }
    
    bool isValidBST(TreeNode* root, TreeNode* &prev){
        if(root == nullptr){
            return true;
        }
        
        bool left = isValidBST(root->left,prev);
        
        if(left == false)
        {
            return false;
        }
        
        if(prev != nullptr and prev->val >= root->val){
            return false;
        }
        prev = root;
        
        bool right = isValidBST(root->right,prev);
        
        return right;
    }
};


// Approach 3 (Passing a range)

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN,LONG_MAX);
    }
    
    bool isValidBST(TreeNode* root, long minValue , long maxValue){
        if(root == nullptr) return true;
        if(root->val >= maxValue or root->val <= minValue) return false;
        return isValidBST(root->left,minValue,root->val) && isValidBST(root->right,root->val,maxValue);
    }
};