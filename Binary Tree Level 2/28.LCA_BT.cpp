// Approach 1
class Solution {
public:
    
    TreeNode* LCANODE = nullptr;
    bool LCA(TreeNode* root, TreeNode* p , TreeNode* q ){
        if(root == nullptr){
            return false;
        }
        
        bool selfPresent = (root == p || root == q);
        
        bool leftPresent = LCA(root->left,p,q);
        bool rightPresent = LCA(root->right,p,q);
        
        if((leftPresent && rightPresent) || (leftPresent &&  selfPresent) || (rightPresent &&  selfPresent)){
            LCANODE = root;
        }
        
        return leftPresent || rightPresent || selfPresent;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        LCA(root,p,q);
        return LCANODE;
    }
};


// Approach 2
class Solution {
public:
    
    
    bool nodeToRootPath(TreeNode* root,int target,vector<TreeNode*> &ans){
        if(root == nullptr){
            return false;
        }
        
        if(root->val == target){
            ans.push_back(root);
            return true;
        }
        
        bool res = nodeToRootPath(root->left,target,ans) || nodeToRootPath(root->right,target,ans);
        
        if(res){
            ans.push_back(root);
        }
        
        return res;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        vector<TreeNode*> ansP;
        vector<TreeNode*> ansQ;
        nodeToRootPath(root,p->val,ansP);
        nodeToRootPath(root,q->val,ansQ);
        
        int i = ansP.size() - 1;
        int j = ansQ.size() - 1;
        
        TreeNode* lca = nullptr;
        
        while(i >= 0 and j >= 0){
            if(ansP[i] != ansQ[j]){
                break;
            }
            
            lca = ansP[i];
            i--;
            j--;
            
        }
        
        return lca;
    }
};


// Approach 3

class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return NULL;
        if(root->val  == p->val || root->val == q->val){
            return root;
        }
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
         TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if(l != NULL && r != NULL){
            return root;
        }
        else if(l != NULL){
            return l;
        }
        else{
            return r;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root, p, q);
    }
};