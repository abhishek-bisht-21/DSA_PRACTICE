// 153. Find Minimum in Rotated Sorted Array
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        
        // When only 1 element is left in our array then it is surely the minimum element.
        while(low < high){
            int mid = low + (high-low)/2;
            // We cannot eleminate the mid cause we haven't checked it and it can also be the minimum ele
            if(nums[mid] < nums[high]){
                high = mid;
            }else{
                // We are eleminating the entire left part cause ele their are obviously bigger.
                low = mid+1;
            }
        }
        
        return nums[low];
    }
};