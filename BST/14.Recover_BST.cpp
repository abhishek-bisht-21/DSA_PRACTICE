


//   Definition for a binary tree node.


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

 // Approach 1->  TC-> O(nlogn) + O(2n) SC -> O(n)
class Solution {
public:
    
    void inOrder(TreeNode* root, vector<int> &arr){
        if(root == nullptr) return;
        
        inOrder(root->left,arr);
        arr.push_back(root->val);
        inOrder(root->right,arr);
    }
    
    void traverseTree(TreeNode* root, vector<int> arr, int &idx){
        if(root == nullptr){
            return;
        }
        
        traverseTree(root->left,arr,idx);
        if(arr[idx] != root->val) root->val = arr[idx];
        idx++;
        traverseTree(root->right,arr,idx);
    }
    
    void recoverTree(TreeNode* root) {
        vector<int>arr;
        inOrder(root,arr);
        sort(arr.begin(),arr.end());
        int i=0;
        traverseTree(root,arr,i);
    }
};



// Appraoch 2 TC-> O(N) SC->O(1)

class Solution {
private: 
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last; 
private: 
    void inorder(TreeNode* root) {
        if(root == NULL) return; 
        
        inorder(root->left);
        
        if (prev != NULL && (root->val < prev->val))
        {
           
            // If this is first violation, mark these two nodes as
            // 'first' and 'middle'
            if ( first == NULL )
            {
                first = prev;
                middle = root;
            }
 
            // If this is second violation, mark this node as last
            else
                last = root;
        }
 
        // Mark this node as previous
        prev = root;
        inorder(root->right); 
    }
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL; 
        prev = new TreeNode(INT_MIN); 
        inorder(root);
        if(first && last) swap(first->val, last->val); 
        else if(first && middle) swap(first->val, middle->val); 
    }
};