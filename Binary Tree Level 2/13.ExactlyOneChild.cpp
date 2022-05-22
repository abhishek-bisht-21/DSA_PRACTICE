// List Of All Single Child Node In Binary Tree 

void exactlyOneChild_(TreeNode* root, vector<int> ans){
	if(root == nullptr or (root->left == nullptr and root->right == nullptr)){
		return;
	}

	if(root->left == NULL or root->right == NULL){
		ans.push_back(root->data);
	}

	exactlyOneChild_(root->left,ans);
	exactlyOneChild_(root->right,ans);
}

vector<int> exactlyOneChild(TreeNode* root){
	vector<int> ans;
	exactlyOneChild_(root,ans);
	return ans;
}