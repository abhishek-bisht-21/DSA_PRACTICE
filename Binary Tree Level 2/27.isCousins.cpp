// 993. Cousins in Binary Tree

// APPRAOCH 1:

class Solution {
public:
    
    void preOrder(TreeNode* root,int x, int y, bool &diffParent){
        
        if(root == NULL) return;
        
        if(root->left and root->right){
        if((root->left->val == x and root->right->val == y) or (root->left->val == y and root->right->val == x)){
            diffParent = false;
        }}
        
        preOrder(root->left,x,y,diffParent);
        preOrder(root->right,x,y,diffParent);
    }
    
    int level(TreeNode* root, int target){
        
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        
        while(!q.empty()){
            int size = q.size();
            while(size-- > 0){
                TreeNode* rn = q.front();
                q.pop();
                
                if(rn->val == target){
                    return level;
                }
                
                if(rn->left){
                    q.push(rn->left);
                }
                
                if(rn->right){
                    q.push(rn->right);
                }
            }
            
            level++;
        }
        
        return level;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return false;
        
        int lx = level(root,x);
        int ly = level(root,y);
        
        bool diffParent = true;
        preOrder(root,x,y,diffParent);
        
        if(lx == ly and diffParent){
            return true;
        }
        
        return false;
    }
};

// APPROACH 2:

class Solution {
public:
    
    void findNodes(TreeNode* root,int x, int y, vector<int> &level,vector<int> &parents,int currlevel, TreeNode* currParent){
        
        if(root == NULL) return;
        if(root->val == x){
            level[0] = currlevel;
            parents[0] = currParent->val; 
        }
        
        if(root->val == y){
            level[1] = currlevel;
            parents[1] = currParent->val; 
        }
        
        findNodes(root->left,x,y,level,parents,currlevel+1,root);
        findNodes(root->right,x,y,level,parents,currlevel+1,root);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        
        vector<int> level = {-1,-1};
        vector<int> parents = {-1,-1};
        
        findNodes(root,x,y,level,parents,0,new TreeNode(-1));
        
        if(level[0] == level[1] and parents[0] != parents[1]){
            return true;
        }
        
        return false;
    }
};