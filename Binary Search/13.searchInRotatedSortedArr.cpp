// 33. Search in Rotated Sorted Array

/*
	Every Time either the left part or right the part will be sorted.
	We can determine where our given element is will exist, either in rp or in lp. 
*/


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
	
		// If the left part is sorted
             else if(nums[si] <= nums[mid]){

		// either it lies in the left part or not    
                if(nums[si] <= target && target <= nums[mid]){
                    ei = mid - 1;
                }
                else{
                    si = mid + 1;
                }
            }
            else{

		// either it lies in the right part or not  
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