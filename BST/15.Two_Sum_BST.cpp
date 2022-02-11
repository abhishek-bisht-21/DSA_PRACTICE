// Approach 1
/*
Inorder of BST is sorted, now in a sorted array apply two sum 

*/

class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    
    void inOrder(Node* root, vector<int> &arr){
        if(root == nullptr) return;
        
        inOrder(root->left,arr);
        arr.push_back(root->data);
        inOrder(root->right,arr);
    }
    
    int isPairPresent(struct Node *root, int target)
    {
    //add code here.
        vector<int> arr;
        inOrder(root,arr);
        
        int size = arr.size();
        int i=0;
        int j=size-1;
        
        while(i < j){
            if(arr[i]+arr[j] > target){
                j--;
            }else if(arr[i]+arr[j] < target){
                i++;
            }else{
                return 1;
            }
        }
        
        return 0;
    }
};


// Appraoch 2

class BSTIterator {
    stack<TreeNode *> myStack;
    bool reverse = true; 
public:
    BSTIterator(TreeNode *root, bool isReverse) {
        reverse = isReverse; 
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        if(!reverse) pushAll(tmpNode->right);
        else pushAll(tmpNode->left);
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node) {
        for(;node != NULL; ) {
             myStack.push(node);
             if(reverse == true) {
                 node = node->right; 
             } else {
                 node = node->left; 
             }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false; 
        BSTIterator l(root, false); 
        BSTIterator r(root, true); 
        
        int i = l.next(); 
        int j = r.next(); 
        while(i<j) {
            if(i + j == k) return true; 
            else if(i + j < k) i = l.next(); 
            else j = r.next(); 
        }
        return false; 
    }
};