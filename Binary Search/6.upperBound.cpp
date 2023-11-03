// Upper Bound -> First element which is greater than X.
/*

TC = O(logn)
arr = [1,3,4,6,6,7,9,10]

x = 6, ub = 7
x = 8, ub = 9
x = 11, ub = Doesn't exist

Inbuilt

int lowerBound(int *arr,int n, int x){
	// Index of the lower bound of x
	int lb = lower_bound(arr+0,arr+n,x) - arr;
}

*/

int upperBound(int *arr, int n, int x){
	int low = 0;
	int high = n-1;
	int ans = n;

	while(low <= high){
		int mid = (low+high)/2;

		if(arr[mid] > x){
			
			low = mid+1;
		}else{
			ans = mid;
			high = mid-1;
		}
	}

	return ans; 
}