/*

AddLeftBoundary
AddLeafNodes
AddRightBoundary -> This have to in reverse order.


*/


class Solution {
public:


    void addLeftBoundary(Node* root, vector<int> &res){
        Node* curr = root->left;
        
        while(curr){
            if(!isLeaf(curr)) res.push_back(curr->data);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    
    
    void addLeafNode(Node* root,vector<int> &res){
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        
        if(root->left) addLeafNode(root->left,res);
        if(root->right) addLeafNode(root->right,res);
    }
    
    
    void addRightBoundary(Node* root, vector<int> &res){
        Node* curr = root->right;
        vector<int> tmp;
        
        while(curr){
            if(!isLeaf(curr)) tmp.push_back(curr->data);
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }
        
        for(int i=tmp.size()-1;i>=0;--i){
            res.push_back(tmp[i]);
        }
    }
    
    bool isLeaf(Node* root){
        if(root->left == NULL and root->right == NULL){
            return true;
        }
        
        return false;
    }

    vector <int> boundary(Node *root)
    {
        //Your code here
        
        vector<int> res;
        if(!root) return res;
        if(!isLeaf(root)){
            res.push_back(root->data);
        }
        addLeftBoundary(root,res);
        addLeafNode(root,res);
        addRightBoundary(root,res);
        return res;
    }
};