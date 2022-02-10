// Approach 1

class Solution {
  public:
    // Return the Kth smallest element in the given BST
    
    void pushAllLeft(Node *root,stack<Node*> &st){
        
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    
    int KthSmallestElement(Node *root, int K) {
        // add code here.
        stack<Node*> st;
        pushAllLeft(root,st);
        
        while(st.size() != 0){
            
             Node* t = st.top(); st.pop();
             K--;
            
            if(K == 0) return t->data;
            pushAllLeft(t->right,st);
        }
        
        return -1;
    }
};

// Approach 2

class Solution {
  public:
    // Return the Kth smallest element in the given BST
    
    int cnt = 0;
    void inOrder(Node* root, int k, int &ans){
        if(root == nullptr){
            return;
        }
        
        inOrder(root->left,k,ans);
        cnt++;
        if(cnt == k){
            ans = root->data;
        }
        inOrder(root->right,k,ans);
    }
    
    int KthSmallestElement(Node *root, int K) {
        // add code here.
        int ans=-1;
        inOrder(root,K,ans);
        return ans;
    }
};