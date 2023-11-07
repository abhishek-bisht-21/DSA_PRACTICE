/*
How to find the Minimum element in the array is the pre-requisite for this question.
Cause the index of the minimum element in the Rotated Sorted Array also tells us 
how many times the Array has been rotated.

Therefore we will keep a Index Varible and store the probable index of the minimum Element.
*/

int findKRotation(vector<int> &arr){
    // Write your code here.    
    int low = 0;
    int high = arr.size()-1;
    int ans = 10e9+7;
    int index = -1;
    
    while(low <= high){
        int mid = (low+high)/2;

        if(arr[low] <= arr[high]){
            if(arr[low] < ans){
                ans = arr[low];
                index = low;
            }
        }

        if(arr[low] <= arr[mid]){
           if(arr[low] < ans){
                ans = arr[low];
                index = low;
            }
            low = mid+1;
        }else{
            if(arr[mid] < ans){
                ans = arr[mid];
                index = mid;
            }
            high = mid-1; 
        }
    }

    return index;
}
