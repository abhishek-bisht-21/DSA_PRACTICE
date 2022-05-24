// 987. Vertical Order Traversal of a Binary Tree
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes; //vertical, level, node->val
        queue<pair<TreeNode*, pair<int,int>>> q; // node, vertical,level
        
        q.push({root,{0,0}});
        
        // Level Order Traversal
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            
            TreeNode* node = p.first;
            int x = p.second.first; // vertical (x-axis)
            int y = p.second.second; // level
            nodes[x][y].insert(node->val);// node's data
            
            if(node->left){
               q.push({node->left,{x-1,y+1}}); 
            }
            if(node->right){
                q.push({node -> right,{x+1,y+1}});
            }
        }
        
        vector<vector<int>> ans;
        for(auto p : nodes){
            vector<int> sans;
            for(auto q: p.second){ //p.second -> map<int,multiset<int>>
                sans.insert(sans.end(), q.second.begin(),q.second.end()); // Storing the entire multiset inside the vector
            }
            ans.push_back(sans);
        }
        
        return ans;
    }
};