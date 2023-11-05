/*

arr[mid] == arr[low] && arr[mid] == arr[high] This is the condition which is causing the problem
and we are not able to decide which half we have to eliminate therefore, whenever we get this 
condition we will keep trimming down our search space.

Rest of the code is exactly same as previous question.

Example: 3 1 2 3 3 3 
Target 
int mid = (0 + 5) / 2 => 2
arr[low] == arr[mid] == arr[high] Because of this we cannot successfully identify the Sorted Half
*/

class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = (low + high)/2;

            if(arr[mid] == target) return true;

            if(arr[mid] == arr[low] && arr[mid] == arr[high]){
                low = low+1;
                high = high-1;
                continue;
            }

            if(arr[mid] >= arr[low]){
                if(arr[low] <= target && target <= arr[mid]){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }else{
                if(arr[mid] <= target && target <= arr[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }
        return false;
    }
};