


class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        queue<pair<Node*,int>> q; // Node, verticalOrder
        map<int, int> mpp; // verticalOrder, Node->data
        q.push({root,0});
        
        while(!q.empty()){
            
            auto p  = q.front();
            q.pop();
            
            Node* node = p.first;
            int line = p.second;
	    // We only want first node in each verticalOrder.
	    // Therefore if that verticalOrder(line) in the map is already filled we won't change it. We will you forward.
            if(mpp.find(line) == mpp.end()) mpp[line] = node->data;
            
            if(node->left){
                q.push({node->left,line-1});
            }
            
            if(node->right){
                 q.push({node->right,line+1});
            }
        }
        
        vector<int> v;
        for(auto p: mpp){
            v.push_back(p.second);
        }
        
        return v;
    }

};