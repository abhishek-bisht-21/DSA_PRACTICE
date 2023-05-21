// Closest Pair From Sorted Arrays
class Solution {
public:
	int closestPair(vector<int>& nums1, vector<int>& nums2, int k) {
		// Your code goes here
		int n = nums1.size();
		int m = nums2.size();

		int i=0,j=m-1,diff=INT_MAX;
		vector<int> ans;

	while(i < n && j >= 0){
		int sum = nums1[i]+nums2[j];
		if(diff > abs(sum-k)){
			diff = abs(sum-k);
			ans = {nums1[i], nums2[j]};
		}

		if(sum >= k){
			j--;
		}else{
			i++;
		}
	}
		return diff;
	}
};