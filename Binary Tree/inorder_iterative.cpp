class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> in;
        if(root == nullptr) return in;
    
        
        while(true){
            if(root != nullptr){
                st.push(root);
                root = root->left;
                
            }else{
                if(st.empty()) break;
                root = st.top();
                st.pop();
                in.push_back(root->val);
                root = root->right;
            }
        }
        
        return in;
    }
};