
// 872. Leaf-Similar Trees
#include <bits/stdc++.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void traversal(TreeNode* root,vector<int> &v){
        if(root == NULL)
            return;
        
        if(root->left == NULL and root->right == NULL){
            v.push_back(root->val);
        }
        
        if(root->left){
            traversal(root->left,v);
        }
        
        if(root->right){
            traversal(root->right,v);
        }
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a;
        vector<int> b;
        traversal(root1,a);
        traversal(root2,b);
        return a == b;
    }
};