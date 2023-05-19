class Solution {
public:
	int countKDifference(vector<int>& nums, int k) {
		// Your code goes here
		int count = 0;
		unordered_map<int, int> umap;

		for(int ele:nums){
			count += umap[ele -k];
			count += umap[ele+k];
			umap[ele]++;
		}

		return count;
	}
};