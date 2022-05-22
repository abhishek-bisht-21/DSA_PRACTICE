// Construct BST from Postorder


Node *constructTree (int post[], int size)
{
      if(size<=0){
       return NULL;
   }
   Node* root=new Node(post[size-1]);
    
   int i=0;
   while(i<size-1 && post[size-1]>post[i]){
       i++;
   }
   
   root->left=constructTree(post+0,i);
   root->right=constructTree(post+i,size-i-1);
   
   return root;
}

// Approach 2


class Solution {
public:
    
    int idx = 0;
    TreeNode* bstFromPostorder(vector<int> postorder, int lr, int rr) {
        
        if(idx < 0  or postorder[idx] < lr or postorder[idx] > rr){
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(postorder[idx--]);
        root->right = bstFromPostorder(postorder,root->val,rr);
        root->left = bstFromPostorder(postorder,lr,root->val);
        
        return root;
    }
    
    
    TreeNode* bstFromPostorder(vector<int>& postorder) {
        int n = postorder.size();
        int lr = -1e9;
        int rr = 1e9;
        return bstFromPreorder(postorder,lr,rr);
    }
};
