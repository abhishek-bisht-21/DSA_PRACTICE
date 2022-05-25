
// 257. Binary Tree Paths
class Solution {
public:
    
    void pathFinder(TreeNode* root, vector<string> &res, string currPath){
        
        if(root == NULL) return;
        
        if(root->left == NULL and root->right == NULL){
            currPath += to_string(root->val);
            res.push_back(currPath);
            return;
        }
        currPath += to_string(root->val)+"->";
        
        
        if(root->left) pathFinder(root->left,res,currPath);
        if(root->right) pathFinder(root->right,res,currPath);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        pathFinder(root,ans,"");
        return ans;
    }
};