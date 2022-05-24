// 872. Leaf-Similar Trees
class Solution {
public:
    
    void traversal(TreeNode* root,vector<int> &v){
        if(root == NULL)
            return;
        
        if(root->left == NULL and root->right == NULL){
            v.push_back(root->val);
        }
        
        if(root->left){
            traversal(root->left,v);
        }
        
        if(root->right){
            traversal(root->right,v);
        }
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a;
        vector<int> b;
        traversal(root1,a);
        traversal(root2,b);
        return a == b;
    }
};