#include <bits/stdc++.h>
using namespace std;


// First Occurence of x
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
	cout << "1st Occurence of  Element at idx: "<< firstOccurence(arr,n,x);
}