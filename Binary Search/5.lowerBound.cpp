//  First element which is greater than or equal to x.
/*

arr = [1,3,5,7,9,10]

x = 7, lb = 7
x = 8, lb = 9
x = 11, lb = Doesn't exist

Inbuilt

int lowerBound(int *arr,int n, int x){
	// Index of the lower bound of x
	int lb = lower_bound(arr+0,arr+n,x) - arr;
}

*/

int lb(int arr[], int n, int x){
	int ans = n;
	int low = 0;
	int high = n-1;

	while(low <= high){

		int mid = (low+high)/2;
		if(arr[mid] >= x){
			ans = mid;
			high = mid-1;
		}else{
			low = mid+1;
		}
	}
	return ans;
}