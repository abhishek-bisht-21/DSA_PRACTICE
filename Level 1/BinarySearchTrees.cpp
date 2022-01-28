#include <bits/stdc++.h>
using namespace std;



/*

All those functions who are dependent on the structure of the tree, those will have no change in them,
Their Time complexity would as it is(Sum and Size).But those algorithms/questions which are dependent on the values
Like Max,Min and Find Those can be Achieved in LogN Time in BST.


*/


// ______________________________________________________Sum,Max,Min,Find,Size in a BST___________________________________________________________________________________


int min(Node* node) {
//     Write your code here

 if (node->left == nullptr) {
    return node->data;
  }

  return min(node->left);

}

int max(Node* node) {
//     Write your code here

    if(node->right == nullptr){
        return node->data;
    }
    
    return max(node->right);


}

int sum(Node* node) {

//     Write your code here

    if(node == nullptr){
        return 0;
    }
    
    int lsum = sum(node->left);
    int rsum = sum(node->right);
    int tsum = lsum + rsum + node->data;
    
    return tsum;


}


int size(Node* node) {

//     Write your code here

    if(node == nullptr){
        return 0;
    }
    
    int lsize = size(node->left);
    int rsize = size(node->right);
    int tsize = lsize + rsize + 1;
    
    return tsize;

}


bool find(Node* node, int data) {

//     Write your code here

    if(node == nullptr){
        return false;
    }
    
    if(node->data == data){
     return true;   
    }
    else if(node->data > data){
       return  find(node->left,data);
    }else{
        return find(node->right,data);
    }

}




// ______________________________________________________________Add a Node in BST__________________________________________________________________________

/*
We are supposed to add nodes only at the leaf nodes. We when we reach the leaf node after
making intelligent calls, and finally from the leaf node we make a make call and reach the
base case we make a new node and then add that new node in the tree.

In this question we are making a change in tree therefore it is important to catch the changed
subtree on either left or right of the root node.

*/

Node* add(Node* node, int val) {

  if (node == nullptr) {
    Node* node = new Node(val);
    return node;
  }

  if (node->data < val) {
    node->right = add(node->right, val);
  }
  if (node->data > val) {
    node->left = add(node->left, val);
  }
  return node;
}




//__________________________________________________________Remove a Node in BST______________________________________________________________

/*

In this we have to handle 3 cases : 
1) Node that we want to remove has no children. it is a leaf node then simply remove it return nullptr.
2) Node we want to remove has one child(either left or right) then remove that node and connect removed node's parent to removed node's child.
3) When both left and right child exist, then we have to find the Max ele in the left subtree, cause it is only element
   which can replace removed node and the tree will remain a bst, as it will be bigger than all its left and smaller than all its right.
   Then finally we have to call on remove function to remove the Left's Max as it is Been used to replace the Removed Node.

*/


Node* remove(Node* root, int data) {
  if (root == nullptr) {
    return nullptr;
  }
  if (data < root->data) {
    root->left = remove(root->left, data);

  }
  else if (data > root->data) {
    root->right = remove(root->right, data);
  }
  else {
	  // both child exist
    if (root->left != nullptr && root->right != nullptr) {
      int lmx = max(root->left);
      root->data = lmx; // Replacing the Left's max at the position of the node which we have to remove.
      root->left = remove(root->left, lmx); // Finally calling to remove the left's max. Cause duplicates in BST is not allowed.
    }
    // Only left or right child exist
    else if (root->left != nullptr) {
      return root->left;
    } else if (root->right != nullptr) {
      return root->right;
    }
    // No child
    else {
      return nullptr;
    }
  }

  return root;
}



// ________________________________________________________________Replace With Sum of Larger________________________________________________

/*

We have to replace each node with the sum of nodes which are greater than that particular node.
And we have to set 0 at the place where no node is bigger than that particular node.
In this question we would 1st goto the extreme right and set zero there and then calculate the sum 
and then make the left call.

In this question right calll will be made and then the left call, cause all the elements on the left subtree
would be smaller than those on the right subtree. Therefore we must 1st calculate the sum of elements at the right
so that when we reach the lsubtree we can replace their values with the sum and also add up the node->data
in the sum.

Inorder of BST visits the nodes in sorted order, is the property we used here. So if we make right call 1st 
then nodes will be visited in reverse of sorted order(decending order).



*/


int sumi = 0;
void replacewithsum(Node*& root) {
  if (root == nullptr) {
    return;
  }
  replacewithsum(root->right);
  int x = root->data;
  root->data = sumi;
  sumi += x;
  replacewithsum(root->left);

}



// ___________________________________________________________LCA OF BST____________________________________________________________________


/*

Lowest common Ancestor in a BST can be figured out more effiecently than in BT. We can make use of BST Properties.
LCA is that point From Root to Node Path from where there paths starts to diverge and they are no longer equal.
Therefore the common element from Root to Node path is our LCA.

In BST we would make calls smartly and use this property, If the both elements are bigger than node->data, make a 
call on right side , if both elements are smaller than node->data then make a call on left side.

Otherwise if on is bigger and other is smaller than node->data, that means there paths are starting to diverge.
Therefore that is our LCA


*/

int ans;
int lca(Node* root,int a,int b){
//     Write your code here

    if(root == nullptr){
        return 0;
    }

    if(root->data > a and root->data > b){
        ans = root->left->data;
        lca(root->left, a, b);
        return ans;
    }else if(root->data < a and root->data < b){
        ans = root->right->data;
        lca(root->right, a, b);
        return ans;
    }else{
        return root->data;
    }

}


// ________________________________________________________PRINT In RANGE__________________________________________________________________


/*
We have to print in range and also in Increasing order, Increasing order  means that we have to print in In Order.
First we will figure out the root of the Subtree who is in the range of D1 and D2. Then we can print in Order.

*/
void pir(Node* node, int d1, int d2)
{
      if (node == NULL) return;
  if (d1 < node->data && d2 < node->data) {
    pir(node->left, d1, d2);
  } else if (d1 > node->data && d2 > node->data) {
    pir(node->right, d1, d2);
  } else { // Tthis node is range that's why we are visiting its left and right child both.
    pir(node->left, d1, d2);
    cout << node->data << endl;
    pir(node->right, d1, d2);
  }
}



// __________________________________________________Target Sum Pair In BST______________________________________________________________


/*


In this question we will make use of find function and we will calculate and compliment of a node,
compliment is defined as the amount left out after reducing the node->data from target.

If the compliment exist in the BST it means there is a pair whose sum is equivalent to the Target value.
We will make sure the comp > node->data, cause we are traversing in order therefore we would get smaller elements
first and there compliment should obviously be greater than there own value.


*/


bool find(Node* node, int data)
{
  if (node == nullptr) {
    return false;
  }

  if (node->data > data) {
    return find(node->left, data);
  }
  else if (node->data < data) {
    return find(node->right, data);
  }
  else {
    return true;
  }
}


void travelAndPrint(Node* root, Node* node, int tar) {

  if (node == nullptr) {
    return;
  }
  travelAndPrint(root, node->left, tar);

  int comp = tar - node->data;
  if (node->data < comp) {
    if (find(root, comp) == true) {
      cout << node->data << " " << comp << endl;
    }
  }
  travelAndPrint(root, node->right, tar);

}



int main(){

}