// 863. All Nodes Distance K in Binary Tree

// APPRAOCH 1:

class Solution {
public:
    
    
    bool nodeToRootPath(TreeNode* root, int key, vector<TreeNode*> &res){
        
        if(root == NULL){
            return false;
        }
        
        
        if(root->val == key){
            res.push_back(root);
            return true;
        }
        
        bool ans = nodeToRootPath(root->left,key,res) || nodeToRootPath(root->right,key,res);
        
        if(ans)
             res.push_back(root);
        
        return ans;
    }
    
    void kDown(TreeNode* root, int k, TreeNode* block, vector<int> &ans){
        if(k < 0 or root == block or root == nullptr){
            return;
        }
        
        if(k == 0){
            ans.push_back(root->val);
        }
        
        kDown(root->left,k-1,block,ans);
        kDown(root->right,k-1,block,ans);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        TreeNode* block = NULL;
        vector<TreeNode*> res;
        nodeToRootPath(root,target->val,res);
        
        vector<int> ans;
        
        for(int i=0;i<res.size();i++){
            kDown(res[i],k-i,block,ans);
            block = res[i];
        }
        
        return ans;
    }
};

// APPROACH 2:

class Solution {
public:
    
    
     void kdown(TreeNode* root, int k, TreeNode* block, vector<int> &ans){
        
        if(root == nullptr or k < 0 or root == block){
            return;
        }
        
        if(k == 0){
            ans.push_back(root->val);
            
        }
        
        kdown(root->left,k-1,block,ans);
        kdown(root->right,k-1,block,ans);

        
    }

int distanceK(TreeNode* root, TreeNode* target, int k, vector<int> &ans){

	if(root == nullptr){
		return -1;
	}

	if(root == target){
		// The initial call when we have just found the target node.
		// then simply calling the kdwon function with block node as null also original k value.
		kdown(root,k,nullptr,ans); 
		return 1;
	}

	int ld  = distanceK(root->left,target,k,ans);
	// If we have recieved ld = 1 or more than that it means we have to calculate
	// kdown from this particular node. But we have recieved ans from left
	// Therefore BlockNode= root->left and k = k-ld. 
	// Is a mark to tell us how much dist we have already covered so we can afford to travel (k-ld) distance more only.
	if(ld != -1){
		kdown(root,k-ld,root->left,ans);
		return ld+1;
	}
	int rd  = distanceK(root->right,target,k,ans);

	if(rd != -1){
		kdown(root,k-rd,root->right,ans);
		return rd+1; 
	}
    
    return -1;
}

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        distanceK(root,target,k,ans);
        return ans;
    }
};