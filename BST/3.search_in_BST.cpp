
// 700. Search in a Binary Search Tree
// All the left are smaller than root and all the right are bigger than the root.
// Largest ele in the left will be smaller than root and smallest element in the right will be bigger than root.
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        
    while (root != nullptr && root->val != val) {
      root = (root->val > val) ? root->left : root->right;
    }
    return root;
    }
};