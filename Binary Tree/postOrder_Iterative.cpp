
// ___________________________________________ Using 2 Stacks________________________________
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> post ;
        if(root == nullptr) return post;
        
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        
        st1.push(root);
        
        while(st1.size() > 0){
            
            TreeNode* t = st1.top();
            st1.pop();
            
            st2.push(t);
            
            if(t->left) st1.push(t->left);
            if(t->right) st1.push(t->right);
            
        }
        
        while(st2.size() > 0){
            post.push_back(st2.top()->val);
            st2.pop();
        }
        
        return post;
    }
};


// ______________________________ Using 1 Stack_______________________________________

class Solution {

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(root == NULL) return postorder;
        stack<TreeNode*> st1;
        TreeNode* current = root;  
        while(current != NULL || !st1.empty()) {
            if(current != NULL){
                st1.push(current);
                current = current->left;
            }else{
                TreeNode* temp = st1.top()->right;
                if (temp == NULL) {
                    temp = st1.top();
                    st1.pop(); 
                    postorder.push_back(temp->val);
                    while (!st1.empty() && temp == st1.top()->right) {
                        temp = st1.top();
                        st1.pop(); 
                        postorder.push_back(temp->val);
                    }
                } else {
                    current = temp;
                }
            }
        }
        return postorder;
    }
};