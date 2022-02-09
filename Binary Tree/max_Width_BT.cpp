// 662. Maximum Width of Binary Tree

// Index Every node in the level Order Traversal
// maxWidth = lastIndex - firstindex + 1 (The last level)
// lc -> 2i+1 and rc -> 2i+2 
// Modified lc -> 2*(i-min)+1 , rc -> 2*(i-min)+2

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if( !root ) return 0;
        queue<pair<TreeNode*, int> > q;
        q.push({root, 1 });
        int ans = 0;
        while(!q.empty() ){
            int size = q.size();
            if (size == 1){
                q.push({q.front().first,1});
                q.pop();
            }
            ans = max( q.back().second - q.front().second + 1, ans);
        
            while( size-->0 ){
                auto node = q.front().first;
                auto idx = q.front().second;
                q.pop();
                if( node->left )
                    q.push({node->left, idx*2});
                if( node->right )
                    q.push({node->right, idx*2+1});
            }
            
        }
        return ans;
    }
};