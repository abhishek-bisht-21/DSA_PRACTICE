#include <bits/stdc++.h>
using namespace std;


// Is Array Sorted

bool isArraySorted(vector<int> arr, int idx){
	if(idx == arr.size() - 1){
		return true;
	}

	return arr[idx] < arr[idx+1] && isArraySorted(arr,idx+1);
}


int main(){

	vector<int> v{1,2,3,4,5,0};
	int idx = 0;
	cout << "Is Array Sorted " << boolalpha << isArraySorted(v,idx);
}