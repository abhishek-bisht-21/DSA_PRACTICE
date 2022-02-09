// Find the Closest Element in BST


// Approach 1
class Solution
{
    public:
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
        
void inOrder(Node* root, int& min_diff, int K){
    if(root){
        inOrder(root->left,min_diff,K) ;
        min_diff = min(min_diff,abs(root->data - K)) ;
        inOrder(root->right,min_diff,K) ;
    }
}
   int minDiff(Node *root, int K){
       int min_diff = INT_MAX ;
       inOrder(root,min_diff,K) ;
       return min_diff ;
   }
};


// Approach 2

class Solution
{
    public:
    //Function to find the least absolute difference between any node
    //value of the BST and the given integer.
    int minDiff(Node *root, int k)
    {
        if(!root)
            return INT_MAX;
        
        //if given value is present in BST then least difference would be 0.
        if( root->data == k )
            return 0;
            
        //if data at current node is more than given value, we try to find 
        //the answer by calling function recursively for left subtree.
        if( root->data > k )
            return min( abs(root->data-k) , minDiff(root->left, k) );
        
        //else we call the function recursively for the right subtree.
        return min( abs(root->data-k) , minDiff(root->right, k) );
    }
};