// 1008. Construct Binary Search Tree from Preorder Traversal


class Solution {
public:
    
    TreeNode* construct(vector<int> pre, int si, int ei){
        
        if(si > ei){
            return nullptr;
        }
        
        TreeNode* root =  new TreeNode(pre[si]);
        int idx = si+1;
        
        while(idx<pre.size() && pre[idx]<pre[si]){
            idx++;
        }
        
        
        
        root->left = construct(pre,si+1,idx-1);
        root->right = construct(pre,idx,ei);
        
        return root;
        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return construct(preorder,0,preorder.size()-1);
    }
};

// Approach 2

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& A) {
        int i = 0;
        return build(A, i, INT_MAX);
    }

    TreeNode* build(vector<int>& A, int& i, int bound) {
        if (i == A.size() || A[i] > bound) return NULL;
        TreeNode* root = new TreeNode(A[i++]);
        root->left = build(A, i, root->val);
        root->right = build(A, i, bound);
        return root;
    }
};

// Approach 3

class Solution {
public:
    
    int idx = 0;
    TreeNode* bstFromPreorder(vector<int> preorder, int lr, int rr) {
        
        if(idx >= preorder.size() or preorder[idx] < lr or preorder[idx] > rr){
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[idx++]);
        root->left = bstFromPreorder(preorder,lr,root->val);
        root->right = bstFromPreorder(preorder,root->val,rr);
        
        return root;
    }
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        int lr = -1e9;
        int rr = 1e9;
        return bstFromPreorder(preorder,lr,rr);
    }
};