// Construct Binary Search Tree FromInOrder Traversal

class Solution {
public:
    
    TreeNode* sortedArrayToBST_Util(vector<int>& nums,int si, int ei){
        
        if(si > ei){
            return nullptr;
        }
        
        int mid = (si+ei)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = sortedArrayToBST_Util(nums,si,mid-1);
        root->right = sortedArrayToBST_Util(nums,mid+1,ei);
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST_Util(nums,0,nums.size()-1);
    }
};