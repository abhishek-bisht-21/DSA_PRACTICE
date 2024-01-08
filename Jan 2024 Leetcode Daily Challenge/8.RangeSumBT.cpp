
#include <bits/stdc++.h>

// 938. Range Sum of BST

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
    
    
    void sumInRange(TreeNode* root, int low, int high, int &sum){
        
        if(root == NULL){
            return ;
        }
        
        if(root->val >= low and root->val <= high){
            sum+=root->val;
        }
        
        sumInRange(root->left,low,high,sum);
        sumInRange(root->right,low,high,sum);
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        int sum = 0;
        sumInRange(root,low,high,sum);
        return sum;
    }
};