/*

Approach 1: 2 for loops to find out all the subarrays, and we can calculate the max product.
	    TC-> O(n^2)

Approach 2: Claim is that either the subarray which is max will start from the starting and 
	    go till a certain pt or the sub array will start from the end and go till a certain pt.
	    Condition that we dont have zeros in our array.

	    4 Cases : Which proves thatno other possible way can be there for maxSubArray Product.

	     
	    1) + (ans) + |||   ans => +,-
	    2) - (ans) + |||   ans => +,-
	    3) + (ans) - |||   ans => +,-
	    4) - (ans) - |||   ans => +,-	 
	   	
	    TC-> O(N)		

*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int cprod = 1;
        int ans = INT_MIN;
        
        for(int i=0;i<nums.size()-1;i++){
            
            cprod*=nums[i];
            ans = max(ans,cprod);
            if(nums[i] == 0){
                cprod = 1;
            }
        }
        
        cprod = 1;
         for(int i=nums.size()-1;i>=0;i--){
            
            cprod*=nums[i];
            ans = max(ans,cprod);
            if(nums[i] == 0){
                cprod = 1;
            }
        }
        
        return ans;
    }
};