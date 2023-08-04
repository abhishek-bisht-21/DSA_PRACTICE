
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


// Approach 2 Preorder Traversal

void leftViewHelper(Node* root, int level, vector<int> &ans){
    if(!root){
        return;
    }
    
    // First time we are encountering a level.
    // It ensures that we are storing the first node from left.
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    
    leftViewHelper(root->left,level+1,ans);
    leftViewHelper(root->right,level+1,ans);
}

vector<int> leftView(Node *root)
{
   // Your code here
   int level=0;
   vector<int> ans;
   leftViewHelper(root,level,ans);
   return ans;
}
