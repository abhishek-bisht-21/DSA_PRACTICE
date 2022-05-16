// 337. House Robber III

// 1. Can't do robbery in connected houses.
// 2. Max amount have to be generated at the end of the robbery.
// 3. Include and exclude technique. At every node we will return 2 values, without doing robbery at that node 
//    how much money we have collected and with doing robbery at that house/node how much we have collected.
//    With Robery(P) and Without Robery(Q).
// 4. At Every Node -> With Robbery at A = Without Robbery(q) at B + Without Robbery(q) at C.
//                     Without Robbery at A = max(l.p,l.q) + max(r.p,r.q)

// APPROACH 1
class Solution {
public:
    
    
        vector<int> HouseRobber_(TreeNode *node)
        {
            if (node == nullptr)
                return {0, 0};

            vector<int> left = HouseRobber_(node->left);
            vector<int> right = HouseRobber_(node->right);

            vector<int> myAns{0, 0};
            myAns[0] = max(left[0], left[1]) + max(right[0], right[1]);
            myAns[1] = left[0] + node->val + right[0];

            return myAns;
        }
    
    int rob(TreeNode* root) {
        
        vector<int> ans = HouseRobber_(root);
        return max(ans[0], ans[1]);
    }
};


// APPROACH 2

class Solution {
public:
    
    class robPair{
        
        public:
        int withRob;
        int withoutRob;
        
        robPair(int withRob, int withoutRob){
            this->withRob = withRob;
            this->withoutRob = withoutRob;
        }
    };
    
    robPair* houseRob(TreeNode* root){
        if(root == nullptr){
            robPair* base = new robPair(0,0); 
            return base;
        }
        
        robPair *lp = houseRob(root->left);
        robPair *rp = houseRob(root->right);
        robPair *mp = new robPair(0,0);
        mp->withRob = lp->withoutRob + root->val +  rp->withoutRob;
        mp->withoutRob = max(lp->withRob,lp->withoutRob) + max(rp->withRob,rp->withoutRob);
        
        return mp;
        
    }
    
    int rob(TreeNode* root) {
        robPair *res = houseRob(root);
        return max(res->withRob,res->withoutRob);
    }
};
