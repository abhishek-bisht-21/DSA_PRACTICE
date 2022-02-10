// Construct a BT from PreOrder and Inorder



class Solution{
    public:
    
    Node* helper(int pre[], int psi, int pei, int in[], int isi, int iei){
        
        if(psi > pei){
            return nullptr;
        }
        
        Node* root = new Node(pre[psi]);
        int find_ele = pre[psi];
        int idx = isi;
        
        while(in[idx] != find_ele){
            idx++;
        }
        
        int left_ele = idx - isi;
        
        root->left = helper(pre,psi+1,psi+left_ele,in,isi,idx-1);
        root->right = helper(pre,psi+left_ele+1,pei,in,idx+1,iei);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        return helper(pre,0,n-1,in,0,n-1);
    }
};



// Construct a BT from PostOrder and InOrder


Node* helper(int post[], int psi, int pei, int in[], int isi, int iei){
    
    if(psi > pei){
        return nullptr;
    }
    
    Node* root = new Node(post[pei]);
    int find_ele = post[pei];
    int idx = isi;
    while(in[idx] != find_ele) idx++;
    int left_ele = idx - isi;
    
    root->left = helper(post,psi,psi+left_ele-1,in,isi,idx-1);
    root->right = helper(post,psi+left_ele,pei-1,in,idx+1,iei);
    
    return root;
}

Node *buildTree(int in[], int post[], int n) {
    // Your code here
    return helper(post,0,n-1,in,0,n-1);
}
