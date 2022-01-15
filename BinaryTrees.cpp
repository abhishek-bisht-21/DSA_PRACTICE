#include <bits/stdc++.h>
using namespace std;



class Node
{
public:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};

class Pair {
    public:
    Node * node = nullptr;
    int state=0;

    Pair(Node *node, int state) {
      this->node = node;
      this->state = state;
    }
  };

int idx = 0;
Node *constructTree(vector<int> &arr)
{

    if (idx == arr.size() || arr[idx] == -1)
    {
        idx++;
        return nullptr;
    }
    Node *node = new Node(arr[idx++]);
    node->left = constructTree(arr);
    node->right = constructTree(arr);
    return node;
}

void display(Node *node)
{
    if (node == nullptr)
        return;
    string str = "";
    str += node->left != nullptr ? to_string(node->left->data) : ".";
    str += " <- " + to_string(node->data) + " -> ";
    str += node->right != nullptr ? to_string(node->right->data) : ".";
    cout << str << endl;

    display(node->left);
    display(node->right);
}




// ___________________________________________Size, Sum, Maximum And Height Of A Binary Tree____________________________________


/*

	We are having faith on our left sub tree and right sub tree that they will give us the correct answer
	then we are computing our own ans. 

	Everything is done in the post order. According to the identity of a operation base case is decided.
	when we reach to the leaf node then our answer starts getting formed.



*/

int size(Node *node)
{
   //write your code here
   if(node == nullptr){
       return 0;
   }

   int lsize = size(node->left);
   int rsize = size(node->right);

   int tsize = lsize+rsize+1;

   return tsize;
}

int height(Node *node)
{
    //write your code here

    if(node == nullptr){
        return -1;
    }

    int lh = height(node->left);
    int rh = height(node->right);

    int th = max(lh,rh) + 1;

    return th;
}

int maximum(Node *node)
{
    //write your code here

    if(node == nullptr){
        return -1e8;
    }

    int lmax = maximum(node->left);
    int rmax = maximum(node->right);

    int tmax = max(node->data,max(lmax,rmax));

    return tmax;

}



int sum(Node *node)
{
    
    //write your code here

    if(node == nullptr){
        return 0;
    }

    int lsum = sum(node->left);
    int rsum = sum(node->right);

    int tsum = node->data + lsum + rsum;

    return tsum;
}



// _______________________________________Levelorder Traversal Of Binary Tree____________________________________________


/* Notes : 

 1) Remove Node
 2) Print Node
 3) Add its children

 Two while loops are used in this approach. Queue is also used. Till the time queue gets empty
 the loop will continue functioning. inner while loop is size dependent

*/
void levelOrder(Node* node) {
    
    queue<Node*>q;
    q.push(node);

    while(!q.empty()){
        int size = q.size();

        while(size-- > 0){

            // Remove the nodes
            Node* front = q.front();
            q.pop();

            // print the nodes
            cout << front->data << " ";

            //add the children
            if(front->left){
                q.push(front->left);
            }

            if(front->right){
                q.push(front->right);
            }
        }

        cout << endl;
    }
}


// _________________________Iterative Pre, Post And Inorder Traversals Of Binary Tree_________________________________

/*
 We are going to store pre, in and post in the string and will print in the end.

 We are going to make use of stack that also of pair kind. Also we are going to use at which level we currently are at.
 According to that we will decide either we are in pre, post or inorder.

 We will continue till the time stack doesn't become empty.

 As we move from one level to anaother we will do level++ 

 Level 1 = Pre order
 Level 2 = in order
 Level 3 = post order also pop that one.



*/


class Pair {
public:
  Node* node = nullptr;
  int state = 0;
  Pair(Node* node, int state) {
    this->node = node;
    this->state = state;
  }
};


void iterativePrePostInTraversal(Node* node) {
  Pair rtp = Pair(node, 1);

  stack<Pair> st;
  st.push(rtp);

  string pre;
  string post;
  string in;

  while (st.size() > 0) {
    Pair upper = st.top();
    if (upper.state == 1) {
      pre += to_string(upper.node->data) + " ";
      upper.state++;
      st.pop();
      st.push(upper);

      if (upper.node->left != nullptr) {
        Pair lp = Pair(upper.node->left, 1);
        st.push(lp);
      }
    }
    else if (upper.state == 2) {
      in += to_string(upper.node->data) + " ";
      upper.state++;
      st.pop();
      st.push(upper);

      if (upper.node->right != nullptr) {
        Pair rp = Pair(upper.node->right, 1);
        st.push(rp);
      }
    }
    else {
      post += to_string(upper.node->data) + " ";
      st.pop();
    }
  }

  cout << pre << endl;
  cout << in << endl;
  cout << post << endl;
}


//_________________________________Find And Nodetorootpath In Binary Tree_______________________________

/*
Find and NodetoRootPath are very similar to each other. In the find function only half the Eular runs.
as soon as we get true it directly runs towards the root node to return.

Meanwhile we can easily trackdown the path from node to the root.

We have solved NodeToRootPath in two ways.




*/

bool find(Node* node, int data) {
  // write your code here
  
  if( node == nullptr){
      return false;
  }
  
  if(node->data == data){
      return true;
  }
  
  return find(node->left,data) || find(node->right,data);
}

// This function is similar to find function.
bool nodeToRootPath(Node* node, int data, vector<Node*>&path){
    if(node == nullptr){
        return false;
    }
    
    if(node->data == data){
        path.push_back(node);
        return true;
    }
    
    bool res = nodeToRootPath(node->left,data,path) || nodeToRootPath(node->right,data,path);
    
    if(res){
        path.push_back(node);
    }
    return res;
}

vector<int> nodeToRootPath(Node* node, int data) {
  // write your code here
  if(node == nullptr){
      vector<int> arr;
      return arr;
  }
  
  if(node->data == data){
      // When we have found our node then we are creating arr vector and adding the node in it. 	  
      vector<int> arr;
      arr.push_back(node->data);
      return arr;
  }
  
  vector<int> larr = nodeToRootPath(node->left,data);
  // If any ans is there in the vector it means that the eular passed from this node in order to reach the desired node.
  if(larr.size() > 0){ 
      larr.push_back(node->data);
      return larr;
  }
  vector<int> rarr = nodeToRootPath(node->right,data);
  // If any ans is there in the vector it means that the eular passed from this node in order to reach the desired node.
  if(rarr.size() > 0){
      rarr.push_back(node->data);
      return rarr;
  }
  
    vector<int> arr;
    return arr;
}


//________________________________Diameter Of A Binary Tree_________________________________________

/*

Diameter of the tree is the max distance between two nodes in a binary tree.
The diameter of a BT can pass through following regions.

1) Root (option1 = lheight + rheight + 2)
2) L subtree ( option2 = ldia)
3) R subtree (option3 = rdia)


*/

//Height function
int height(Node *node)
{
    return node == nullptr ? -1 : max(height(node->left), height(node->right)) + 1; // for no of edges: -1, and in terms of no of nodes return 0;
}

// Appraoch 1 --> O(N^2)
int diameter(Node *root)
{
   if(root == nullptr){
       return -1;
   } 

   int lh = height(root->left);
   int rh = height(root->right);

   int option1 = lh + rh + 2; // when root is passing through the root.

   int option2 = diameter(root->left); // when diameter is in left subtree
   int option3 = diameter(root->right);// when diameter is in right subtree

   return max(option1,max(option2,option3));
}

// Approach 2 --> O(N)
int dia = -1e8;
int diameter_btr(Node* root){

	if(root == nullptr){
		return -1;
	}

	int lht = diameter_btr(root->left);
	int rht  = diameter_btr(root->right);

	int height = max(lht,rht) + 1;
	dia = max(dia,lht+rht+2);


	return height;
}


int diameter(Node *root){
    diameter_btr(root);
    return dia;
}

// ____________________________________________Print K Levels Down_________________________________

void kLevelsDown(Node* node, int k){
  // write your code here
  if(node==nullptr){
      return;
  }

  if(k == 0){
      cout<<node->data<<endl;
      return;
  }

  kLevelsDown(node->left,k-1);
  kLevelsDown(node->right,k-1);
}


//_______________________________________Transform To Left-cloned Tree__________________________________

/*

We are keeping the faith that left sub tree and right sub tree knows how to do this work. 
They will return the correct ans to our root node. Now our work is to create a clone of
root node and connect that clone with root as well as to the left sub tree.
Right sub tree will be directly connected to our root node.

*/

Node* createLeftCloneTree(Node* node) {
  // write your code here
  
  if(node == nullptr){
      return nullptr;
  }
  
  Node* left = createLeftCloneTree(node->left);
  Node* right = createLeftCloneTree(node->right);
  Node* newNode = new Node(node->data,left,nullptr);
  
  node->left = newNode;
  node->right = right;
  return node;

}

//   __________________________________________Transform To Normal From Left-cloned Tree___________________

/*

On the left call(node->left->left) we are doing this cause root node will have its clone attached to its immediate left.
So are calling on rootNodes->left->left and having faith on it that we knows how to transform the cloned tree back to normal tree.
On the right side we are making call on the immediate right only cause its a left cloned tree and right subtree wont be 
needing special attention.

In the post order we are connecting node->left with ans from left subtree and node->right with ans from right subtree



*/


Node* transBackFromLeftClonedTree(Node* node) {
    
    if(node == nullptr){
        return nullptr;
    }
    
    Node* lnn = transBackFromLeftClonedTree(node->left->left);
    Node* rnn = transBackFromLeftClonedTree(node->right);
    
    node->left = lnn;
    node->right = rnn;
    
    return node;
    
}



// _______________________________________Remove Leaves In Binary Tree____________________________


/*
Whenever we are making changing the binary tree then we have to collect newly created 
left subtree and  right subtree in the recursive calls.



*/

Node* removeLeaves(Node* node) {
  // write your code here
  
  if(node == nullptr){
      return nullptr;
  }

 
    if (node->left == nullptr && node->right == nullptr)
  {
    free(node);
    return nullptr;
  }

  node->left = removeLeaves(node->left);
  node->right = removeLeaves(node->right);


  return node;


}


// ____________________________1325. Delete Leaves With a Given Value__________________________________

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* r, int target) {
    if (r == nullptr) return nullptr;
    r->left = removeLeafNodes(r->left, target);
    r->right = removeLeafNodes(r->right, target);
    return (r->left == r->right && r->val == target) ? nullptr : r;
    }
};
  


//_______________________________________________Print Single Child Nodes____________________________

/*


In the parent nullptr is passed initially that's why we have made a check whether parent is null our not.
We are doing our work in preorder. We are checking if a node has only left child or only right child
then only we are printing it.

*/


void printSingleChildNodes(Node* node, Node* parent) {
  // write your code here
  
  if(node == nullptr){
      return ;
  }
  
  if(parent != nullptr && parent->left == node && parent->right == nullptr){
      cout << node->data << endl;
  }else if(parent != nullptr and parent->right == node and parent->left == nullptr){
      cout << node->data << endl;
  }
  
  printSingleChildNodes(node->left,node);
  printSingleChildNodes(node->right,node);
  
 

}


// _______________________________Tilt Of Binary Tree_____________________________________

/*

In this function we are actually calculating the sum of the all the nodes in the Binary tree and 
meanwhile also calculating the tilt of the binary tree. 
tilt of node is defined as the abs(left_sub_Tree_Sum - right_sub_Tree_Sum)



*/


class Solution {
public:
    
     int helper(TreeNode* root, int &tilt){
        if(root == nullptr){
            return 0;
        }
        
        // Will return l sub tree sum and also will make a change in tilt
        int lsum = helper(root->left,tilt);
        // Will return r sub tree sum and also will make a change in tilt
        int rsum = helper(root->right,tilt);
        
        int tsum = lsum + rsum + root->val;
        
        int ltilt = abs(lsum - rsum);
        tilt+=ltilt;
        
        return tsum;
        
    }
    
    
    int findTilt(TreeNode* root) {
       int tilt = 0;
       int sum = helper(root,tilt);
       return tilt;
    }
};






// __________________________________________________Is A Binary Search Tree________________________________________



/*

For node to be BST -> node->data >= max_of_left_subtree and node->data <= min_of_right_subtree.
For a tree to be BST -> left subtree and right subtree should BST and node should be BST.

To calculate the min and max at each node. The parent requires and the min of both left subtree and 
right subtree and similarly to calculate the max of the parent node it requires the max of left and
right subtree both. 

Each node should have min and max calculated for it, cause we never know that node can be either
left child of the parent our the right child of the parent.


*/


class bst {
public:
  bool isbst = false;
  int max = 0;
  int min = 0;
};

bst Bst(Node* node) {

  if (node == nullptr)
  {
    bst bres;
    bres.isbst = true;
    bres.max = INT_MIN;
    bres.min = INT_MAX;
    return bres;
  }
  bst l = Bst(node->left);
  bst r = Bst(node->right);

  bst ans;

  ans.max = max(node->data, max(l.max, r.max));
  ans.min = min(node->data, min(l.min, r.min));

  if (l.isbst == true && r.isbst == true && (l.max < node->data && r.min > node->data)) {
    ans.isbst = true;
  }
  return ans;

}


//____________________________________Is Balanced Tree______________________________

/*

 A binary tree is balanced if for every node the gap between height's of it's left and right subtree is not more than 1.
 In this question we are actually calculating the height of the binary tree and at each node's postorder figuring
 out that whether that node is balanced or not.

 Balanced => abs(lht - rht) <= 1.

*/

bool isbal = true;

int isbalance(Node* node)
{
  if (node == nullptr)
  {
    return -1;
  }

  int l = isbalance(node->left);
  int r = isbalance(node->right);

  int gap = abs(l - r);
  if (gap > 1)
  {
    isbal = false;
  }
  int th = max(l, r) + 1;

  return th;

}

// ________________________________________________Print Nodes K Distance Away________________________________

/*

For this question we would be needing two functions. NodeToRootPath and PrintKLevelsDown with blockNode.
We would first call on NodeToRootPath function and collect its ans in an vector then we would run a loop
over that vector and call printKLevelsDown on it one by one and keep updating the blocknode and also 
the distance we can travel with each successive node. 

With each successive node the distance we can travel will decrease (k-i).
BlockNode will be previous node from which we called  PrintKLevelsDown
cause we gonna avoid going on the side which not actually k dist apart 
from the original node but it might seams so when we call printKlevelsdown function.
Cause ultimately we want k distance apart nodes from the target node.


*/


vector<Node*> nodeToRootPath(Node *node, int data) {
    vector<Node*> temp;
    if (node == nullptr){
      return temp;
    }

    vector<Node*> ans;
    if(node->data == data) {
      ans.push_back(node);
      return ans;
    }
    vector<Node*> left = nodeToRootPath(node->left, data);
    if(left.size() > 0) {
      left.push_back(node);
      return left;
    }
    vector<Node*> right = nodeToRootPath(node->right, data);
    if(right.size() > 0) {
      right.push_back(node);
      return right;
    }
    return temp;
  }


void printKLevelsDown(Node *node, int k, Node *block)
{
    if (node == nullptr || node == block)
        return;

    if (k == 0)
    {
        cout << node->data <<endl;
        return;
    }

    printKLevelsDown(node->left, k - 1, block);
    printKLevelsDown(node->right, k - 1, block);
}


void printKNodesFar(Node *node, int data,int k)
{
    vector<Node*> ans;
    ans = nodeToRootPath(node,data);
    Node *blockNode = nullptr;
    for(int i=0;i<ans.size();i++){
        printKLevelsDown(ans[i],k-i,blockNode);
        blockNode = ans[i];
    }

    return;

}

// _____________________________________________________Path To Leaf From Root In Range____________________________

/*

We are given the low and high and we have to check that the of nodes from root to leaf remain under this given
range only and if they are in this range. Then we can print them.

We will do our work in the pre order and we will keep adding node->data in the sum and also in the path.
When we reach the leaf node then we haven't yet added the leaf nodes data in the sum, so we will 1st add it 
then we will put on a check there if they are in the range or not.

If they are in the range then we will print it otherwise simply return.



*/


void pathToLeafFromRoot(Node* node, string path,int sum, int lo, int hi){

  if(node == nullptr){
    return;
  }

  if(node->left == nullptr and node->right == nullptr){
    sum+=node->data;
    if(sum >= lo and sum <= hi){
      cout << path + to_string(node->data) << endl;
    }

    return;
  }

  pathToLeafFromRoot(node->left,path+to_string(node->data)+" ",sum+node->data,lo,hi);
  pathToLeafFromRoot(node->right,path+to_string(node->data)+" ",sum+node->data,lo,hi);


}


// ____________________________________________ LARGEST BST SUBTREE__________________________________________________________

/*

For this We have to first write the code for isBST and then we have to continue from there onwards.
If the subtree is isBST then root of the current subtree is node itself and left->size + right->size + 1
will be its overall size.  

If it is not a BST itself then if left->size > right->size then left->size will be size of the subtree and
left's root will be root of the subtree and vice-versa if right->size > left->size.

But how can we say that if current node is not bst then its left subtree or right subtree will be BST and
how can we directly consider them as an option for Largest BST Subtree.


*/


// This is class two things are added root and size.
class bst {
public:
  bool isbst = false;
  int max = 0;
  int min = 0;
  Node* root = nullptr;
  int size = 0;
};


bst Bst(Node* node) {

  // In the base case setting some values for the bst class and return object of class bst.
  // From the leaf node they will set there values and return to its parent telling them that
  // they are valid bst and they will update there min and max also.
  if (node == nullptr)
  {
    bst bres;
    bres.isbst = true;
    bres.max = INT_MIN;
    bres.min = INT_MAX;
    return bres;
  }


  bst l = Bst(node->left);
  bst r = Bst(node->right);


  bst ans;

  //Doing the basic math to calculate min and max for a node. Cause my parent requires 
  // my min and max to calculate its own.
  ans.max = max(node->data, max(l.max, r.max));
  ans.min = min(node->data, min(l.min, r.min));

  // checking if ans is a valid bst or not.
  if (l.isbst == true && r.isbst == true && (l.max < node->data && r.min > node->data)) {
    ans.isbst = true;
  }

    if (ans.isbst == true)
  {
    ans.root = node;
    ans.size = l.size + r.size + 1;
  }
  else if (l.size > r.size)
  {
    ans.root = l.root;
    ans.size = l.size;
  }
  else
  {
    ans.root = r.root;
    ans.size = r.size;
  }

  return ans;
}




int main(){

}