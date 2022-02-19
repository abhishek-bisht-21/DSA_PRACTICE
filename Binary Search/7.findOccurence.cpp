int firstOccurence(int *arr, int n, int x){

	int low = 0;
	int high = n-1;
	int ans = -1;

	while(low <= high){
		
		int mid = (high+low)/2;
		// If found at the mid then return the mid
		if(arr[mid] == x){
			ans = mid;
			high = mid - 1;
			continue;
		}
		// Never lies on the right half
		else if( arr[mid] > x){
			high = mid - 1;
		}
		// Never lies on the left half
		else{
			low = mid+1;
		}
	}

	return ans;
}

// Last Occurence of x
int LastOccurence(int *arr, int n, int x){

	int low = 0;
	int high = n-1;
	int ans = -1;

	while(low <= high){
		
		int mid = (high+low)/2;
		
		if(arr[mid] == x){
			ans = mid;
			low = mid + 1;
			continue;
		}
		// Never lies on the right half
		else if( arr[mid] > x){
			high = mid - 1;
		}
		// Never lies on the left half
		else{
			low = mid+1;
		}
	}

	return ans;
}


int findOccurence(int arr[], int n,int x){
	int ans = LastOccurence(arr,n,x) - firstOccurence(arr,n,x);
	return ans;
}