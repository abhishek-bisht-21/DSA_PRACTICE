// Is Binary Tree Heap

class Solution {
  public:
  
    bool isCBT(Node* root){
        
        if(root == NULL){
            return true;
        }
        
        bool flag = false;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            
            Node* p = q.front();
            q.pop();
            
            if(p == NULL){
                flag = true;
            }else{
                if(flag)
                    return false;
                q.push(p->left);
                q.push(p->right);
            }
        }
        
        return true;
    }
    
    bool heapOrderProp(Node* root){
        if(root == NULL){
            return true;
        }
        
        if(root->left == NULL and root->right){
            return true;
        }
       else{
           return (root->data > root->right->data) && (root->data > root->left->data);
       }
       
       return heapOrderProp(root->left) && heapOrderProp(root->right);
    }
  
    bool isHeap(struct Node* tree) {
        // code here
        
        return (isCBT(tree) and heapOrderProp(tree)); 
    }
};