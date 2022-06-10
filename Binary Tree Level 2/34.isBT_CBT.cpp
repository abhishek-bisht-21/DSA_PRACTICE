// 958. Check Completeness of a Binary Tree

// APPROACH 1 : Recurrsion DFS

class Solution {
public:
    
    bool isCBT(TreeNode* root, int i, int node_Count){
        if(root == NULL){
            return true;
        }
        
        if(i >= node_Count){
            return false;
        }
        
        else{
            bool left = isCBT(root->left,2*i+1,node_Count);
            bool right = isCBT(root->right,2*i+2,node_Count);
            
            return (left && right);
        }
    }
    
    int nodeCount(TreeNode* root){
        
        if(root == NULL){
            return 0;
        }
        
        int lCount = nodeCount(root->left);
        int rCount = nodeCount(root->right);
        
        return lCount + rCount + 1;
    }
    
    bool isCompleteTree(TreeNode* root) {
        
        int node_Count = nodeCount(root);
        return isCBT(root,0,node_Count);
    }
};


// APPROACH 2 : BFS

//please upvote, if you like my approach.
//pre-request : basic knowledge of level order traversal.
//we traverse the tree level wise, whenever we encounter a null value we keep track of that. 
//if our first null is last value in binary tree, then our tree is complete binary tree. else not complete binary tree.
bool isCompleteTree(TreeNode* root) {
        bool value = false;
        if(root==NULL)
            return true;
        queue<TreeNode *> q;
        q.push(root);
        while(q.size()>0)
        {
            TreeNode *p = q.front();
            q.pop();
            if(p==NULL)
            {
                value=true;
            }
            else
            {
                if(value)
                    return false;
                q.push(p->left);
                q.push(p->right);
            }
        }
        return true;
    }