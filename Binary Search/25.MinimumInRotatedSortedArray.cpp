/*

// Minimum in Rotated Sorted Array

1) Eliminate the left half or right half.
2) Identify the sorted half.
3) Sorted Half may or may  not contain the answer. Therefore we will pick the minimum from it.
4) We will store the minimum element in the sorted half in the ans and Eliminate the sorted half.
5) Now we will perform the binary search in the Other half.

Example: 

arr1 = 4 5 6 7 0 1 2
arr2 = 7 8 1 2 3 4 5 6
arr3 = 4 5 1 2 3
arr4 = 1 2


*/

int findMin(vector<int>& arr)
{
	// Write your code here.
	int n = arr.size();
	int low = 0;
	int high = n-1;
	int ans = INT_MAX;

	while(low <= high){
		int mid = (low+high)/2;

		// When Search Space is already sorted
		// Then arr[low] will be smallest in array
		if(arr[low] <= arr[high]){
			ans = min(arr[low], ans);
			break;
		}

		if(arr[mid] >= arr[low]){
			ans = min(ans, arr[low]);
			low = mid+1;
		}else{
			ans = min(arr[mid], ans);
			high = mid-1;
		}
	}

	return ans;
}