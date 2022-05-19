
// ____________________________________________________Root to node path Approach 1___________________________________________

 bool nodeToRootPath(TreeNode *root, int key,vector<TreeNode*>& res){

	if(root == nullptr){
		return false;
	}

	if(root->val == key){
	    res.push_back(root);
	    return true; 
	}

	// Short circuiting, if we are getting true from one side it wont check the other simply return to the below call in the stack.
	bool ans = nodeToRootPath(root->left,key,res) || nodeToRootPath(root->right, key,res);
	
	if(ans){ // As soon as it gets true it runs towards the root node, We can catch the nodes in the meanwhile.
	    res.push_back(root);
	}
	
	return ans;
}

vector<TreeNode*> nodeToRootPath(TreeNode* root, int data)
{
    vector<TreeNode*> res;
    nodeToRootPath(root,data,res);
    return res;
}


// Root to node path Approach 2
vector<TreeNode*> nodeToRootPath(TreeNode* root, int data){
	if(root == nullptr){
		return {};
	}

	if(root->val == data){
		return {root};
	}

	// Calling on left subtree 
	vector<TreeNode*> left = nodeToRootPath(root->left,data);
	if(left.size() != 0){ // Having some size it means that we are on correct path
		left.push_back(root);
		return left;
	}

	// Calling on right subtree 
	vector<TreeNode*> right = nodeToRootPath(root->right,data);
	if(right.size() != 0){ // Having some size it means that we are on correct path
		right.push_back(root);
		return right;
	}

	return {};
}