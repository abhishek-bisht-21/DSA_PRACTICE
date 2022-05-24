vector <int> diagonalSum(Node* root) {
    // Add your code here
    
    vector<int>v;
   if(!root) return {};
   queue<Node*>q;
   q.push(root);
   while(!q.empty())
   {
       int n=q.size();
       int sum=0;
       for(int i=0;i<n;i++)
       {
           Node *t=q.front();q.pop();
           
           while(t)
           {   
               sum+=t->data;
               if(t->left) q.push(t->left);
               t=t->right;
           }
       }
       v.push_back(sum);
   }
   return v;
}