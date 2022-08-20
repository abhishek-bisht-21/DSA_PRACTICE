#include <bits/stdc++.h>
using namespace std;


// Is Array Sorted

bool isArraySorted(vector<int> arr, int idx){
	if(idx == arr.size() - 1){
		return true;
	}

	return arr[idx] < arr[idx+1] && isArraySorted(arr,idx+1);
}


// Get Array Sum

int arraySum(vector<int> &arr, int idx){
	if(idx == arr.size()){
		return 0;
	}

	int small_ans = arraySum(arr,idx+1);
	int myans = small_ans + arr[idx];
	return myans;
}


// Linear Search 

int linearSearch(vector<int> &arr, int idx, int key){
	if(idx == arr.size()){
		return -1;
	}

	if(arr[idx] == key){
		return idx;
	}

	return linearSearch(arr,idx+1,key);
}


int main(){

	vector<int> v{1,2,3,4,5,0};
	int idx = 0;
	int key = 5;
	cout << "Is Array Sorted " << boolalpha << isArraySorted(v,idx) << endl;
	cout << "Array Sum " << arraySum(v,idx) << endl;
	cout << "Element " << key << " is present at index "<< linearSearch(v,idx,key);

}