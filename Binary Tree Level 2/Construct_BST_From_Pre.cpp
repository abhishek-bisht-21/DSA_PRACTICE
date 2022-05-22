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