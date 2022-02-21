// 154. Find Minimum in Rotated Sorted Array II

class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int si = 0;
        int ei = n-1;
        
        while(si < ei){
            int mid = si + (ei-si)/2;
            // Bring ei at the mid cause we haven't checked mid yet and it can also be the Minimum element.
            if(arr[mid] < arr[ei]){
                ei = mid;
            }
            // Remove the entire lpart of array. Cause element from si to mid are obviously bigger.
            else if(arr[mid] > arr[ei]){
                si = mid+1;
            }
            // When the mid is equal to ei then we can't straight up eleminate the rpart of array.
            // Instead we will eleminate that specific element only.
            else{
                ei--;
            }
        }
        return arr[si];
    }
};