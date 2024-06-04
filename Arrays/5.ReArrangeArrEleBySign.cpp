// https://leetcode.com/problems/rearrange-array-elements-by-sign/


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // SC -> O(N)
        // TC -> (2N)
        vector<int> pos;
        vector<int> neg;
        int n = nums.size();

        //O(N)
        for(int ele: nums){
            if(ele > 0){
                pos.push_back(ele);
            }else{
                neg.push_back(ele);
            }
        }

        // O(N)
        for(int i=0;i<n/2;i++){
            nums[2*i] = pos[i]; // positive numbers will always be on even idx
            nums[2*i+1] = neg[i]; // negative numbers will always be on odd idx
        }

        return nums;
    }
};