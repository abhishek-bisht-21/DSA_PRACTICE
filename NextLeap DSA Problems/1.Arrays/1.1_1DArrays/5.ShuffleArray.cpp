class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int N=nums.size();
        for(int i=0;i<N/2;i++){
            ans.push_back(nums[i]);
            ans.push_back(nums[(i+n)%N]);
        }
        return ans;
    }
};