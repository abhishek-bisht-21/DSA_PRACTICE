//  Greatest Value which is smaller than equal to the given key

int findFloor(TreeNode* root, int key){

	int floor = -1;

	while(root){


		if(root->data == key){
		floor = root->data;
		return floor;
		}

		if(key < root->data){
			root = root->left;
		}else{
			floor = root->data;
			root = root->right;
		}	
	}
	



	return floor;
}