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







//__________________________________________________________Remove a Node in BST______________________________________________________________






// ________________________________________________________________Replace With Sum of Larger________________________________________________






// ___________________________________________________________LCA OF BST____________________________________________________________________






// ________________________________________________________PRINT In RANGE__________________________________________________________________





// __________________________________________________Target Sum Pair In BST______________________________________________________________




int main(){

}