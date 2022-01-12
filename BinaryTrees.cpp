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




int main(){

}