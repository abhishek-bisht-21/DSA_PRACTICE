vector<int> leftView(Node *root)
{   
     vector<int> ans;
    if(root == nullptr){
        return ans;
    }
   
   queue<Node*> q;
   q.push(root);
   
   while(!q.empty()){
       int size = q.size();
       ans.push_back(q.front()->data);
       while(size-- > 0){
           Node* rn = q.front();
           q.pop();
           if(rn->left){
               q.push(rn->left);
           }
           
           if(rn->right){
               q.push(rn->right);
           }
       }
   }
   
   return ans;
}