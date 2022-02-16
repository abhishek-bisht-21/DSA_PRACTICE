/*

	Subsequence -> Every element has an option to become the part of the subarray or not.
	Width -> Difference Btw minElement and maxElement.
	Brute Force : 1) Find out all the subsequence. O(2^n)
	 	      2) Find maxWidth O(n)
		      3) TC -> O(2^n * n)


	Claim : If we sort the array then also the width is going to remain same.
		   It wont have any Effect.

		   1) Sort the Array.
		   2) find out how many times an element is behaving as max and min.
		   3) Keep a ans variable and for every element, calculate the find the 2 point.
		      ans = 2^q*2(When 2 is Max) - 2^p*2(When 2 is Min)
		      Do this for Every Element in the array.		     	

*/

class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        long ans = 0;
        long mod = 1e9+7;
        int n = nums.size();
        
        long power[n];
        power[0] = 1;
        
        for(int i=1;i<n;i++){
            power[i] = (power[i-1]*2) % mod;
        }
        
        
        for(int i=0;i<n;i++){
            ans = (ans+ nums[i] * (power[i] - power[n-i-1])) % mod;
        }
        
       
        return (int)ans;
    }
};