#include <bits/stdc++.h>
using namespace std;

int findEle(int *arr, int n, int x){

	int low = 0;
	int high = n-1;

	while(low <= high){
		
		int mid = (high+low)/2;
		// If found at the mid then return the mid
		if(arr[mid] == x){
			return mid;
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

	return -1;
}

int findEle_Recursive(int *arr, int low, int high,int target){
	if(low <= high){
		return -1;
	}

	int mid = low + (high-low)/2;

	if(target == arr[mid]){
		return mid;
	}
	else if(target > arr[mid])
	{
		return findEle_Recursive(arr, mid+1, high, target);
	}
	return findEle_Recursive(arr, low,mid-1, target);
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

	cout << "found Element at idx: "<< findEle(arr,n,x);
}