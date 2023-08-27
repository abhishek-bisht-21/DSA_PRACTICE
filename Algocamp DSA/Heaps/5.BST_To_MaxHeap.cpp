class Solution{
  public:
    void inorder(Node* root, vector<int>&ans)
    {
        if(root==NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
        
        return;
    }
    int i=0;
    void postorder(Node* root, vector<int>&ans)
    {
        if(root==NULL) return;
        postorder(root->left,ans);
        postorder(root->right,ans);
        //if(i<ans.size()) swap(root->data,ans[i++]);
        root->data = ans[i++];
        return;
    }
    void convertToMaxHeapUtil(Node* root)
    {
        vector<int> ans;
        inorder(root,ans);
        postorder(root,ans);
        
    }    
};