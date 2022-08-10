#include <bits/stdc++.h>
using namespace std;


bool isArraySorted(vector<int> arr, int idx , int n){
	if(idx == n-1){
		return true;
	}

	return (arr[idx] < arr[idx+1] && isArraySorted(arr,idx+1,n));
}

int main(){


	vector<int> v{1,2,3,4,5,0};

	cout << "Is Vector sorted : " << boolalpha << isArraySorted(v,0,v.size());
	return 0;
}