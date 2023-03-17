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

      // Is Leaf Node. Cause Leaf Node is Always a Heap.Always follow heapOrderProp	  
      if(root->left == NULL && root->right == NULL){

          return true;

      }

      // Only Having Left Child	
      if(root->right == NULL){

          return root->data > root->left->data;

      }

      // Having Both the child Nodes	
      else{

          bool left = isMaxOrder(root->left);

          bool right = isMaxOrder(root->right);

          

          return (left && right && root->data > root->left->data && root->data > root->right->data);

      }

  }

    bool isHeap(struct Node* tree) {

        int index = 0;

        int countNode = countNodes(tree);

        
	// 2 Necessary Condition for BT to be a Heap.
	// Complete Binary Tree and HeapOrderProperty => True
        if(isCBT(tree, index, countNode) && isMaxOrder(tree)){

            return true;

        }

        else{

            return false;

        }

    }

};