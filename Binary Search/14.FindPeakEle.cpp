
// 162. Find Peak Element

/*
1) If the Array has just one element Handle that case. Return 0
2) Check if the mid element is the Peak or not.
3) If the Array has only single peak then in that case, 3 Conditions will be there.
    i) Either the peak will on the right of the mid.
    ii) Either the peak will be on the left of the mid.
    iii) Or the peak will be at the mid only.
4) If the mid is on the increasing  curve then for sure the peak will be on the right. Eliminate the Left Half.
5) If the mid is in the decreasing curve then for sure the peak will be on the left. Eliminate the right half. If the Left Element is Greater abnd Right Element
is smaller then it means its on decreasing curve.

*/

// Approach 1
class Solution {
public:
    int findPeakElement(vector<int>& arr) {

    int n = arr.size();
    if(n == 1) return 0;
    if(arr[0] > arr[1]) return 0;
    if(arr[n-1] > arr[n-2]) return n-1;

    int si = 1;
    int ei = n-2;

    while(si <= ei){
        int mid = (si+ei)/2;

        if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]){
            return mid;
        }
        // Increasing curve. Eliminate Left
        else if(arr[mid] > arr[mid-1]){
            si = mid+1;
        }else{
            // Decreasing curve
            ei = mid-1;
        }
    }

    return -1;
    }
};



// Approach 2
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int si = 0;
        int ei = n-1;
        
        while(si < ei){
            int mid = (si+ei)/2;
            
            if(nums[mid] > nums[mid+1]){
                ei = mid;
            }else{
                si = mid+1;
            }
        }
        
        return si;
    }
};