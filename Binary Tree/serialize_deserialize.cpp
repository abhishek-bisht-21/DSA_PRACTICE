
//297. Serialize and Deserialize Binary Tree


// Serialize -> Level Order


// Deserialize -> use queue and start tarversing the string. Keep pushing the char in the queue and make nodes and connections.


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(root == nullptr)
            return ""; 
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            
            TreeNode* p = q.front();
            q.pop();
            
            if(p == NULL) s.append("#,"); // signifies that no child

            else s.append(to_string(p->val)+',');
            
            if(p != nullptr){
		// Pushing both the child so that we can know whats the status of both.
		// if both are null then place two(2) ##
                q.push(p->left);
                q.push(p->right);
            }
        }
        
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data.size() == 0) return NULL; 
        stringstream s(data);
        string str; 
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*> q; 
        q.push(root); 

        while(!q.empty()) {
            
            TreeNode *node = q.front(); 
            q.pop(); 
            
            getline(s, str, ',');
            if(str == "#") {
                node->left = NULL; 
            }
            else {
		    // if not null then push ele in the queue and
		    // make a node and attach it on the left
                TreeNode* leftNode = new TreeNode(stoi(str)); 
                node->left = leftNode; 
                q.push(leftNode); 
            }
            
            getline(s, str, ',');
            if(str == "#") {
                node->right = NULL; 
            }
            else {
		     // if not null then push ele in the queue and
		    // make a node and attach it on the right
                TreeNode* rightNode = new TreeNode(stoi(str)); 
                node->right = rightNode;
                q.push(rightNode); 
            }
        }
        return root; 
    }
};