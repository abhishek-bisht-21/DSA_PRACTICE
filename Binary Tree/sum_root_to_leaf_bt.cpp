// 129. Sum Root to Leaf Numbers


class Solution {
public:
    
    void rootToLeaf(TreeNode* root, string psf, vector<string> &ans){
        if(root == nullptr){
            return ;
        }
        
        if(root->left == nullptr and root->right == nullptr){
            psf+=to_string(root->val);
            ans.push_back(psf);
        }
        
        rootToLeaf(root->left,psf+to_string(root->val), ans);
        rootToLeaf(root->right,psf+to_string(root->val), ans);
    }
    
    int sumNumbers(TreeNode* root) {
        vector<string> ans;
        string psf;
        rootToLeaf(root,psf,ans);
        int sum = 0;
        for(auto ele : ans){
            
            stringstream geek(ele);
 
            int x = 0;
            geek >> x;
            sum+=x;
        }
        
        return sum;
        
    }
};