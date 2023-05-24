// 53. Maximum Subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
	// current sum and overall sum
        int currSum = 0;
        int overallSum = INT_MIN;

        for(int i=0;i<nums.size();i++){

            currSum += nums[i];
	    // Self made man , don't need ancestral loan.
	    // nums[i] > 0 and currSum < 0
            if(currSum <  nums[i]){
                currSum = nums[i];
            }

            overallSum = max(overallSum,currSum);
        }

        return overallSum;
    }
};