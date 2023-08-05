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