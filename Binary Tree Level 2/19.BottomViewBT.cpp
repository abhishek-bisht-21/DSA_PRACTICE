class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        queue<pair<Node*,int>> q; // node , verticalOrder;
        map<int,int> mpp; // line(verticalOrder), node->data
        q.push({root,0});
        
        while(!q.empty()){
            
            auto p = q.front();
            q.pop();
            
            Node* node = p.first;
            int line = p.second;
            mpp[line] = node->data;
            
            if(node->left)
                q.push({node->left,line-1});
            if(node->right)
                q.push({node->right,line+1});
        }
        
        for(auto p : mpp){
            ans.push_back(p.second);
        }
        
        return ans;
        
    }
};