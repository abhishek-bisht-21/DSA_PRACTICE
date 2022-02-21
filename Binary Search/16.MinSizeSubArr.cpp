
// 209. Minimum Size Subarray Sum


class Solution {
public:
    
    // check if there exist a subarray of size len, which has sum >= target
    bool blackbox(vector<int> arr, int target,int len){
       
        // First find the first len size subarray sum
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (i >= len) sum -= arr[i - len];
            sum += arr[i];
            if (sum >= target) return true;
        }
        return false;
    }
    
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        int low = 1;
        int high = n;
        int ans = 0;
        while(low <= high){
            int mid = (low+high)/2;
            
            if(blackbox(nums,target,mid) == true){
                high = mid-1;
                ans = mid;
            }else{
                low = mid+1;
            }
        }
   
        return ans;
    }
};