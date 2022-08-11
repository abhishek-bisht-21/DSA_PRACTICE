#include <bits/stdc++.h>
using namespace std;


int firstIndex(vector<int> arr, int idx, int key){
	if(idx == arr.size()){
		return -1;
	}

	if(arr[idx] == key){
		return idx;
	}

	return firstIndex(arr,idx+1,key);
}

int main(){

	vector<int> v{20,10,30,50,40,10,30,40};
	int key = 10;
	cout << "First Index of "<< key << " is " << firstIndex(v,0,key);
	return 1;
}