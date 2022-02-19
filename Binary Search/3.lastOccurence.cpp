#include <bits/stdc++.h>
using namespace std;


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


int main(){

	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	int x;
	cin>>x;

	// arr -> 1 2 2 2 3 4 4 4 5
	cout << "Last Occurence of  Element at idx: "<<LastOccurence(arr,n,x);
}