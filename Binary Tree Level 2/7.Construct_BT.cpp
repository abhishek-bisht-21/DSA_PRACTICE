// 105. Construct Binary Tree from Preorder and Inorder Traversal
class Solution {
public:
    
    TreeNode* construct(vector<int> pre, int psi, int pei, vector<int>in,int isi, int iei){
        
        if(psi > pei){
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(pre[psi]);
        int find_ele = pre[psi];
        
        int idx = isi;
        
        while(in[idx] != find_ele){
            idx++;
        }
        
        int left_ele = idx - isi;
        
        root->left = construct(pre,psi+1,psi+left_ele,in,isi,idx-1);
        root->right = construct(pre,psi+left_ele+1,pei,in,idx+1,iei);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return construct(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};



// 106. Construct Binary Tree from Inorder and Postorder Traversal

class Solution {
public:
    
     TreeNode* construct(vector<int> post, int psi, int pei, vector<int> in,int isi, int iei){
        
        if(psi > pei){
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(post[pei]);
        int find_ele = post[pei];
        
        int idx = isi;
        
        while(in[idx] != find_ele){
            idx++;
        }
        
        int left_ele = idx - isi;
        
        root->left = construct(post,psi,psi+left_ele-1,in,isi,idx-1);
        root->right = construct(post,psi+left_ele,pei-1,in,idx+1,iei);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
         return construct(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1);
        
    }
};