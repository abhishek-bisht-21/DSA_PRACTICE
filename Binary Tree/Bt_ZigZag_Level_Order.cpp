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