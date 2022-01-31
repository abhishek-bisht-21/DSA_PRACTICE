// 102. Binary Tree Level Order Traversal

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
         if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            
            int size = q.size();
            vector<int> v;
            while(size > 0){
                
                TreeNode* rv = q.front();
                q.pop();
                size--;
                
                
                v.push_back(rv->val);
                
                if(rv->left)
                    q.push(rv->left);
                
                if(rv->right)
                    q.push(rv->right);
            }
            
            ans.push_back(v);
            
        }
        
        return ans;
    }
};