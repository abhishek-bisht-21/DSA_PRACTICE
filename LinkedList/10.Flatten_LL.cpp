Node* mergeTwoLL(Node* l1, Node* l2){
    
    Node* temp = new Node(0);
    Node* dummy = temp;
    
    while(l1 != nullptr and l2 != nullptr){
        
        if(l1->data > l2->data){
            temp->bottom = l2;
            temp = temp->bottom;
            l2 = l2->bottom;
        }else{
            temp->bottom = l1;
            temp = temp->bottom;
            l1 = l1->bottom;
        }
    }
    
    if(l1) temp->bottom = l1;
    else temp->bottom = l2;
    return dummy->bottom;
}
    
Node *flatten(Node *root)
{
   // Your code here
   if(root == nullptr or root->next == nullptr){
       return root;
   }
   
   root->next = flatten(root->next);
   root = mergeTwoLL(root,root->next);
   return root;
}