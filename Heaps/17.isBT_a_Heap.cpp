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




// Approach 2:


// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {

  public:

  int countNodes(struct Node* root){

      if(root == NULL)
      return 0;
      int ans = 1 + countNodes(root->left) + countNodes(root->right);
      return ans;
  }

  bool isCBT(struct Node* root, int i, int cnt){

      if(root == NULL){
          return true;
      }
      if(i >= cnt){
          return false;
      }
      else{
          bool left = isCBT(root->left, 2*i+1, cnt);
          bool right = isCBT(root->right, 2*i+2, cnt);
          return (left && right);
      }
  }

  bool isMaxOrder(struct Node* root){

      if(root->left == NULL && root->right == NULL){
          return true;
      }
      if(root->right == NULL){
          return root->data > root->left->data;
      }

      else{
          bool left = isMaxOrder(root->left);
          bool right = isMaxOrder(root->right);
          return (left && right && root->data > root->left->data && root->data > root->right->data);
      }
  }

    bool isHeap(struct Node* tree) {

        int index = 0;
        int countNode = countNodes(tree);
        return isCBT(tree, index, countNode) && isMaxOrder(tree);

    }

};