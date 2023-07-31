// Approach 1 -> Just like level order traversal, just that after every level
//               We are switching the direction of filling the temp array.



/**
 * 
 * We are declaring the size of temp array and finding out the index, from where we have to
 * start filling the array.  
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while(!q.empty()){
            int size = q.size();
            vector<int> temp(size);

            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();

		// Find the position to fill the node's value.	
                int index = (leftToRight) ? i : (size-1-i);
                temp[index] = node->val;

                if(node->left){
                    q.push(node->left);
                }

                
                if(node->right){
                    q.push(node->right);
                }

            }
            // After the level is completed.
            leftToRight  = !leftToRight;
            ans.push_back(temp);
            
        }

        return ans;
    }
};


// Approach 2 -> We have Simply kept a flag and we are performing our normal
// LEvel order traversal, but after every level we are reversing the temp array.
// So that we can maintain the left to right and right to left order.


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;

        while(!q.empty()){
            int size = q.size();
            vector<int> v;
            while(size-- > 0){
                TreeNode* node = q.front();
                q.pop();
                v.push_back(node->val);

                if(node->left){
                    q.push(node->left);
                }

                if(node->right){
                    q.push(node->right);
                }
            }

              if(flag)
                reverse(v.begin(), v.end());
            ans.push_back(v);
            flag = !flag;
        } 

        return ans;
    }
};