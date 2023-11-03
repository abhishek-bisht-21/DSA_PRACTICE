// Floor => Largest number in array <= x
// Ceil => Smallest number in array >= x

/*

arr = [10 , 20, 30, 40, 50]
x = 25
Floor = 20
Ceil = 30

*/


int calculateCeil(vector<int> &arr, int n, int x){
	int low = 0;
	int high = n-1;
	int ans = -1;

	while(low <= high){
		int mid = (low + high)/2;

		if(arr[mid] >= x){
			ans = arr[mid];
			high = mid-1;
		}else{
			low = mid+1;
		}
	}

	return ans;
}

int calculateFloor(vector<int> &arr, int n, int x){

	int low = 0;
	int high = n-1;
	int ans = -1;

	while(low <= high){
		int mid = (low + high)/2;

		if(arr[mid] <= x){
			ans = arr[mid];
			low = mid+1;
		}else{
			high = mid-1;
		}
	}

	return ans;
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	
	int floor = calculateFloor(a, n, x);
	int ceil = calculateCeil(a, n, x);

        return {floor, ceil};
}