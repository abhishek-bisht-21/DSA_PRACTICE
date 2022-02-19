#include <bits/stdc++.h>
using namespace std;


// Last Occurence of x
int recBS(int *arr, int low, int high, int x){

	if(low < high){

		int mid = (low+high)/2;

		if(arr[mid] == x){
			return mid;
		}else if(arr[mid] > x){
			return recBS(arr,low,mid-1,x);
		}else{
			return recBS(arr,mid+1,high,x);
		}
	}

	return -1;

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

	// arr -> 1 2 3 4 5
	cout << "Found Element at idx: "<<recBS(arr,0,n-1,x);
}