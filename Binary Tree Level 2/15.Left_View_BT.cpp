
// Left View of Binary Tree 
vector<int> leftView(Node *root)
{
   // Your code here
   if(!root){
       return {};
   }
   
   vector<int> ans;
   queue<Node*> q;
   q.push(root);
   
   while(!q.empty()){
       int size = q.size();
       ans.push_back(q.front()->data);
       while(size > 0){
           Node* rn = q.front();
           q.pop();
           size--;
           
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