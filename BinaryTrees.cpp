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








int main(){

}