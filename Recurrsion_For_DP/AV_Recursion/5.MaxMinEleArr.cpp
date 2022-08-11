#include <bits/stdc++.h>
using namespace std;

int maxElement(vector<int> &arr, int idx){

	if(idx == arr.size()){
		return INT_MIN;
	}

	int maxEle = maxElement(arr,idx+1);
	if(arr[idx] > maxEle){
		return arr[idx];
	}

	return maxEle;
}

int minElement(vector<int> &arr, int idx){
	if(idx == arr.size()){
		return INT_MAX;
	}

	int minEle = minElement(arr,idx+1);
	if(arr[idx] < minEle){
		return arr[idx];
	}

	return minEle;
}


int main(){

	vector<int> v{1,2,3,4,5,6,7,8,9,10};
	cout << "Max Element in array "<< maxElement(v,0) << " Min Element in array "<<minElement(v,0);

	return 1;
}