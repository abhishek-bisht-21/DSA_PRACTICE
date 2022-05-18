// 894. All Possible Full Binary Trees

/*

FULL BT can only be made if we have ODD Number of Nodes.
If We have 7 Nodes in total, then we will create root nodes on 1,3,5
Root Node At 1 : Left Subtree Node  -> 1 and Right Subtree Nodes -> 5
Root Node At 3: Left Subtree Nodes -> 3 and Right Subtree Nodes -> 3
Root Node At 5 : Left Subtree Nodes -> 5 and Right Subtree Nodes -> 1


*/

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
         if (n == 1) {
    vector<TreeNode*> base;
    base.push_back(new TreeNode(0));
    return base;
  }
  vector<TreeNode*> ans;
  for (int i = 1; i < n; i += 2) {
    vector<TreeNode*> left = allPossibleFBT(i);
    vector<TreeNode*> right = allPossibleFBT(n - i - 1);
    for (TreeNode* l : left) {
      for (TreeNode* r : right) {
        TreeNode* root = new TreeNode(0);
        root->left = l;
        root->right = r;
        ans.push_back(root);
      }
    }
  }
  return ans;
    }
};