// 863. All Nodes Distance K in Binary Tree

// Approach 1
class Solution {
public:
    
     bool nodeToRootPath(TreeNode *root, int key,vector<TreeNode*>& res){

	if(root == nullptr){
		return false;
	}

	if(root->val == key){
	    res.push_back(root);
		return true;
	}

	bool ans = nodeToRootPath(root->left,key,res) || nodeToRootPath(root->right, key,res);
	
	if(ans){
	    res.push_back(root);
	}
	
	return ans;
}
    
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


    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
         vector<TreeNode*> path;
         nodeToRootPath(root,target->val,path);
        
        vector<int> ans;
        TreeNode *block = nullptr;
        
        for(int i=0;i<path.size();i++){
            kdown(path[i], k - i,block,ans);
            block = path[i];
        }
        
        return ans;
    }   
};