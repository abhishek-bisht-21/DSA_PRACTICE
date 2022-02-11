//173. Binary Search Tree Iterator

//Approach 1
class BSTIterator {
public:
    
    void inOrder(TreeNode* root,vector<TreeNode*> &ans){
        
        if(root == nullptr){
            return;
        }
        
        inOrder(root->left,ans);
        ans.push_back(root);
        inOrder(root->right,ans);
        
        
    }
    
     vector<TreeNode*> ans;
     int p=0;
    
     BSTIterator(TreeNode* root) {
        
       
        inOrder(root, ans);
        
    }
    
    int next() {
        return ans[p++]->val;
    }
    
    bool hasNext() {
        
        return (p < ans.size() ? true : false);
    }
};


// Appraoch 2

class BSTIterator {
public:
    
    list<TreeNode *> st;
    
    BSTIterator(TreeNode* root) {
        insertAllLeft(root,st);
    }
    
    void insertAllLeft(TreeNode *node, list<TreeNode *> &st)
    {
        while (node != nullptr)
        {
            st.push_front(node);
            node = node->left;
        }
    }

    
    int next() {
        TreeNode* rn = st.front(); st.pop_front();
        // Add AllLeft for removed node's right
        insertAllLeft(rn->right,st);
        return rn->val;
    }
    
    bool hasNext() {
        return st.size() != 0;
    }
};