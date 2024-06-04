// https://leetcode.com/problems/maximum-product-subarray/description/

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