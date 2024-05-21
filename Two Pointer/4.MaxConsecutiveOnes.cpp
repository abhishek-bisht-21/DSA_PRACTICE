// 1004. Max Consecutive Ones III -> Longest subarray with at most k zeros
// TC: O(2*N)
class Solution {

public:
    int longestOnes(vector<int>& nums, int k) {
        int count = 0;
        int j = -1;
        int ans = 0;
        
        for(int i=0;i<nums.size();i++){
            
            if(nums[i] == 0){
                count++;
            }
            
            while(count > k){
                j++;
                if(nums[j] == 0)
                    count--;
            }
            
            int len = i - j;
            ans = max(ans,len);
        }
        
        return ans;
    }
};


// Approach 2:

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros = 0;
        int left = 0;
        int ans = 0;
        int right = 0;
        int n = nums.size();


        while(right < n){
            
            if(nums[right] == 0){
                zeros++;
            }

            if(zeros > k){
                if(nums[left] == 0){
                    zeros--;
                }
                left++;
            }
        
            int len = 0;
           if(zeros <= k){
            len = right - left+1;
           }


            ans = max(ans,len);

           right++;
        }
        
        return ans;
    }
};