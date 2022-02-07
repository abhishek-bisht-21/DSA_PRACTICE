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