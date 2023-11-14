// 33. Search in Rotated Sorted Array

/*
	Every Time either the left part or right the part will be sorted.
	We can determine where our given element is will exist, either in rp or in lp. 

    Our element would lie in 1 of the 2 sorted parts (either Left part or right).
    If we somehow reduce our search space such that we find the half in which our target element is present.
    Then it is a simple Binary Search.
*/


class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = (low + high)/2;
            // If the left part is sorted
            if(arr[mid] == target){
                return mid;
            }
            else if(arr[mid] >= arr[low]){
                // either it lies in the left part or not  
                if(arr[low] <= target && target <= arr[mid]){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }else{
                // either it lies in the right part or not  
                if(arr[mid] <= target && target <= arr[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }

        return -1;
    }
};