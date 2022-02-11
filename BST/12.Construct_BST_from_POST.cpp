

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