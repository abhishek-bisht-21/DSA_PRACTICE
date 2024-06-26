//// Kth Ancestor in a Tree


Node* solve(Node* root, int &k, int node){
    if(!root) return NULL;
    if(root->data == node) return root;
    
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);

    if((leftAns && !rightAns) || (!leftAns && rightAns)){
        k--;
        if(k<=0){
            k = INT_MAX;
            return root;
        }
        return leftAns != NULL ? leftAns: rightAns;
    }
    
    return NULL;
}

int kthAncestor(Node *root, int k, int node){
    Node* ans = solve(root, k, node);
    if(!ans || ans->data==node) return -1;
    else return ans->data;
}