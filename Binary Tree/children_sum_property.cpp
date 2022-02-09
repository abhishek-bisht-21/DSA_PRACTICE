class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
        queue<Node*> q;
        q.push(root);
        if(root->left==NULL and root->right==NULL)
        {
            return true;
        }
        
        while(q.empty()==false)
        {
            Node* temp = q.front();
            q.pop();
            
            int sum=0;
            if(temp->left!=NULL)
            {
                sum+=temp->left->data;
                q.push(temp->left);
            }
            
            if(temp->right!=NULL)
            {
                sum+=temp->right->data;
                q.push(temp->right);
            }
            
            if(sum!=0 && sum!=temp->data)
            {
                return false;
            }
        }
        return true;
    }
};
