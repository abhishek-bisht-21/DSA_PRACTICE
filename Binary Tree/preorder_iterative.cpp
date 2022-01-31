class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        if(root == nullptr)
            return {};
        stack<TreeNode*> st;
        st.push(root);
        vector<int> pre;
        
        while(!st.empty()){
            
            TreeNode* t = st.top();
            st.pop();
           pre.push_back(t->val);
            
            if(t->right)
                st.push(t->right);
            if(t->left)
                st.push(t->left);
        }
        
        return pre;
    }
};