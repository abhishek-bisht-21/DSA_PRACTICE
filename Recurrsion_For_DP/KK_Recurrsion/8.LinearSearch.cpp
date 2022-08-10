#include <bits/stdc++.h>
using namespace std;


int linearSearchRec(int *arr, int idx, int key, int size){
	
	if(idx == size-1){
		if(arr[idx] == key){
			return idx;
		}

		return -1;
	}

	if(arr[idx] == key){
		return idx;
	}

	return linearSearchRec(arr,idx+1,key,size);
}

int main(){

	int key = 3;
	int arr[] = {1,2,3,4,5};
	int size = sizeof(arr)/sizeof(int);

	cout << "Index of Element searched is " << linearSearchRec(arr,0,key,size);

	return 1;
}