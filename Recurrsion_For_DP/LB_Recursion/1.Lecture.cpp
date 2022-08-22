#include <bits/stdc++.h>
using namespace std;


// Is Array Sorted

bool isArraySorted(vector<int> arr, int idx){
	// Base Case
	if(idx == arr.size() - 1){
		return true;
	}

	return arr[idx] < arr[idx+1] && isArraySorted(arr,idx+1);
}


// Get Array Sum

int arraySum(vector<int> &arr, int idx){
	// Base Case
	if(idx == arr.size()){
		return 0;
	}

	int small_ans = arraySum(arr,idx+1);
	int myans = small_ans + arr[idx];
	return myans;
}


// Linear Search 

int linearSearch(vector<int> &arr, int idx, int key){
	// Base Case
	if(idx == arr.size()){
		return -1;
	}

	if(arr[idx] == key){
		return idx;
	}

	return linearSearch(arr,idx+1,key);
}



// Binary Search
int BinarySearch(vector<int> &arr, int s, int e, int key){

	if(s <= e){
		int mid = s + (e-s)/2;

		if(arr[mid] == key){
			return mid;
		}

		if(arr[mid] > key){
			BinarySearch(arr,s,mid-1,key);
		}
			
		return  BinarySearch(arr,mid+1,e,key);
		
	}

	return -1;
}

// Nth Term of Fibonacci Series

int fibo(int n){
	if(n < 2){
		return n;
	}

	return fibo(n-1) + fibo(n-2);
}

int main(){

	vector<int> v{1,2,3,4,5,8};
	int idx = 0;
	int key = 5;
	int size = v.size();
	// cout << "Is Array Sorted " << boolalpha << isArraySorted(v,idx) << endl;
	// cout << "Array Sum " << arraySum(v,idx) << endl;
	// cout << "LS : Element " << key << " is present at index "<< linearSearch(v,idx,key) << endl;
	// cout << "BS : Element " << key << " is present at index "<< BinarySearch(v,0,size-1,key) << endl;
	cout << "Fibonacci of Nth Term : " << fibo(6) << endl;


}