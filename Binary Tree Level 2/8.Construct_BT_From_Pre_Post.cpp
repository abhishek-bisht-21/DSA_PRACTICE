// Why Only Full Binary Tree For The Construction Of Tree Using Pre And Post Traversal

class Solution {
public:
    
    TreeNode* constructFromPrePost(vector<int>& pre,int psi,int pei,vector<int>& post,int Psi,int Pei) {
       
        if(psi > pei){
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(pre[psi]);
        if(psi == pei) return root;
        int find_ele = pre[psi+1];
        
        int idx = Psi;
        while(post[idx] != find_ele){
            idx++;
        }
        
        int tnel = idx - Psi + 1; 
        
        root->left = constructFromPrePost(pre,psi+1,psi+tnel,post,Psi,idx);
        root->right = constructFromPrePost(pre,psi+tnel+1,pei,post,idx+1,pei);
        
        return root;
    }
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return constructFromPrePost(preorder,0,n-1,postorder,0,n-1);
    }
};