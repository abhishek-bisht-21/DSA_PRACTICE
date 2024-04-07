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
    int pathSum(TreeNode* root, int target) 
    {
        if(!root)return 0;
        unordered_map<long long,int>mp;
        mp[0]=1;
        int ans=0;
        calculate(root,target,mp,ans,0);
        return ans;
    }
    void calculate(TreeNode*root,int target,unordered_map<long long,int>&mp,int &ans,long long sum)
    {
        if(!root)
        return;
        sum+=root->val;
        if(mp.find(sum-target)!=mp.end())
        {
            ans+=mp[sum-target];
        }
        mp[sum]++;
        calculate(root->left,target,mp,ans,sum);
        calculate(root->right,target,mp,ans,sum);
        mp[sum]--;
        return;
    }
};