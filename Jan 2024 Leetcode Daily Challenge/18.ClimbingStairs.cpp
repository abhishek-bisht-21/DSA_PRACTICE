// 70. Climbing Stairs

class Solution {
public:
    
    
    
    int climbStairs_helper(int n, vector<int>& ans){
        
        if(n <= 1){
            return 1;
        }
        
        if(ans[n] > 0){
            return ans[n];
        }
        
        int op1 = climbStairs_helper(n-1,ans);
        int op2 = climbStairs_helper(n-2,ans);
        ans[n] = op1+op2;
        return op1 + op2;
    }
    
    int climbStairs(int n) {
        vector<int> ans(n+1,0);
        int res = climbStairs_helper(n,ans);
        return res;
    }
    
};