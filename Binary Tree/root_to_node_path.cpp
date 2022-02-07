
bool find(TreeNode* root, int data, vector<int> &ans){
    if(root == nullptr){
        return false;
    }

    if(root->val == data){
        ans.push_back(root->val);
        return true;
    }

    bool res = find(root->left,data,ans) || find(root->right,data,ans);
    if(res){
        ans.push_back(root->val);
    }

    return res;
}

vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    find(A,B,ans);
    reverse(ans.begin(),ans.end());
    return ans;

}