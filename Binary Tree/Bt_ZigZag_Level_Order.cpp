// 103. Binary Tree Zigzag Level Order Traversal
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while(!q.empty()){
            int n = q.size();
            vector<int> v;
           while(n-- > 0){
                TreeNode* top = q.front();
                q.pop();
                if(top->left != NULL)
                    q.push(top->left);
                if(top->right != NULL)
                    q.push(top->right);
                v.push_back(top->val);
            }
            if(flag)
                reverse(v.begin(), v.end());
            ans.push_back(v);
            flag = !flag;
        }
        return ans;
    }
};


// ___________________ Without Reverse Function______________________________


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        
        while(!q.empty()){
            int size = q.size();
            vector<int> sans(size);
            for(int i=0;i<size;i++){
                
                TreeNode* rv = q.front();
                q.pop();
                
                int index = (leftToRight == true) ? i : (size - 1 - i);
                
                sans[index] = rv->val;
                
                if(rv->left) q.push(rv->left);
                if(rv->right) q.push(rv->right);
            }
            
            leftToRight = !leftToRight;
            ans.push_back(sans);
        }
        
        return ans;
    }
};