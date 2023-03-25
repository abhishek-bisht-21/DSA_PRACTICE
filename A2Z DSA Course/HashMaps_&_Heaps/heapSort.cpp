#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


bool compareTo(vector<int> &arr, bool isIncreasingint i, int j){
	if(isIncreasing){
		return arr[i] > arr[j];
	}else{
		return arr[i] < arr[j];
	}
}

voi downHeapify(vector<int> &arr, bool isIncreasing, int pIdx, int li){

	int lci = 2*pIdx+1;
	int rci = 2*pIdx+2;
	int maxIdx = pIdx;

	if(lci <= li && compareTo(arr,isIncreasing,lci,maxIdx))
		maxIdx = lci;
	if(rci <= li && compareTo(arr,isIncreasing,rci,maxIdx))
		maxIdx = rci;
	
	if(maxIdx != pIdx){
		swap(arr[maxIdx], arr[pIdx]);
		downHeapify(arr,isIncreasing,maxIdx,li);
	}
}


void heapSort(vector<int> &arr, bool isIncreasing){

	int li = arr.size()-1;
	for(int i=li;i>=0;i--){
		downHeapify(arr,isIncreasing,i,li);
	}

	while(li >= 0){
		swap(arr[0], arr[li--]);
		downHeapify(arr,isIncreasing,0,li);
	}
}

int main(){

	vector<int> arr = {10,20,30,-2,-3,-4,5,6,7,8,9,22,11,13};
	
	// inc/dec sorted
	heapSort(arr,true);

	return 0;
}