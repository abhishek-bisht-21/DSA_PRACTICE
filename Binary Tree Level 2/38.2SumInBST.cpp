// Approach 1: Inorder Traversal of BST is SORTED
// Find the Inorder of BST and then the question is simply transformed to a 2 sum question.                     

class Solution {
public:

    void inOrder(TreeNode* root, vector<int> &ans){
        if(root == NULL)
            return;

        inOrder(root->left,ans);
        ans.push_back(root->val);
        inOrder(root->right,ans);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        inOrder(root,arr);

        int n = arr.size();
        int i = 0;
        int j = n-1;

        while(i < j){
            if(arr[i] + arr[j] > k){
                j--;
            }else if(arr[i] + arr[j] < k){
                i++;
            }else{
                return 1;
            }
        }

        return 0;

    }
};


// Approach 2: We are doing a preOrder traversal and storing the elements we have
// visisted till now in a set and then checking whether (Target-root->val)
// is present in the set or not. In that way we will know whether a valid pair 
// exists or not.

class Solution {
public:

    set<int> s;
    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr){
            return false;
        }

        if(s.find(k-root->val) != s.end()) return true;
        s.insert(root->val);
	// We are checking the left subtree and then Right subtree post that.
	// 1. Both Pair of nodes can be found in leftsubtree only
	// 2. Both Pair of nodes can be found in RightSUbtree only.
	// 3. Pair of nodes can be found: 1 in lst and other in rst.    
        return findTarget(root->left,k) || findTarget(root->right,k);
    }
};