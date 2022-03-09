class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int si = 0;
        int ei = n-1;
        
        while(si <= ei){
            int mid = (si+ei)/2;
            
            if(nums[mid] == target){
                return mid;
            }
              
            // low to mid is sorted
             else if(nums[si] <= nums[mid]){
                if(nums[si] <= target && target < nums[mid]){
                    ei = mid - 1;
                }
                else{
                    si = mid + 1;
                }
            }
            // mid to high part is sorted
            else{
                if(nums[mid] < target && target <= nums[ei]){
                    si = mid+1;
                }
                else{
                    ei = mid - 1;
                }
            }   
        }
        
        return -1;
    }
};