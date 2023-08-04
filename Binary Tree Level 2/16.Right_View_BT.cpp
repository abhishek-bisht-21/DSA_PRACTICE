

// APPROACH 1:
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        if(!root) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            while(size > 0){
                if(size == 1){
                    ans.push_back(q.front()->val);
                }
                
                TreeNode* rn = q.front();
                q.pop();
                size--;
                
                if(rn->left){
                    q.push(rn->left);
                }
                
                if(rn->right){
                    q.push(rn->right);
                }
            }
        }
        
        return ans;
    }
};

// APPROACH 2:

class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> ans;
       if(root == nullptr) return ans;
       
       map<int,int> mpp; //level and data
       queue<pair<Node*, int>>q; // node and level
       q.push({root,0}); 
       
       while(!q.empty()){
           
           auto p  = q.front();
           q.pop();
           
           int level = p.second;
           Node* node = p.first;
           
           if(mpp.find(level) == mpp.end()){
               mpp[level] = node->data;
           }
           
           if(node->right){
               q.push({node->right,level+1});
           }
           
           if(node->left){
               q.push({node->left,level+1});
           }
       }
       
       for(auto p : mpp){
           ans.push_back(p.second);
       }
       
       return ans;
    }
};

// APPROACH 3:

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
        if(root == nullptr){
            return ans;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            ans.push_back(q.front()->val);
            
            while(size-- > 0){
                
                TreeNode* rn = q.front();
                q.pop();
                
                if(rn->right){
                    q.push(rn->right);
                }
                
                if(rn->left){
                    q.push(rn->left);
                }
            }
        }
        
        return ans;
    }
};


// Approach 4: Recursive Solution. Reverse Preorder (Root Right Left)

class Solution {
public:

    // Since we are moving Right at first, therefore ensures that it is first 
    //node from right or right most node Of that particular level.
    void reversePreOrderHelper(TreeNode* root, int level, vector<int> &ans){
        if(root == NULL){
            return;
        }

        // First Time we are coming across any level.
        if(level == ans.size()){
            ans.push_back(root->val);
        }

        if(root->right)
            reversePreOrderHelper(root->right,level+1,ans);
        if(root->left)
            reversePreOrderHelper(root->left,level+1,ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        int level = 0;
        vector<int> ans;
        reversePreOrderHelper(root,level,ans);    
        return ans;
    }
};